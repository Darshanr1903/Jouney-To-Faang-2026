import hashlib
import base64
import time
import uuid
import httpx


BASE62_ALPHABET="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
def encode_base62(num:int)->str:
    if num==0:
        return BASE62_ALPHABET[0]
    base62_chars=[]
    while num>0:
        base62_chars.append(BASE62_ALPHABET[num%62])
        num=num//62
    return ''.join(reversed(base62_chars))

def decode_base62(base62_str:str)->int:
    if(len(base62_str)==0):
        return 0
    num=0
    base=62
    for char in (base62_str):
        num=num*62+BASE62_ALPHABET.find(char)
    
    return num

def generate_secure_hash(long_url:str,length:int=7):
    #generating a unique string
    unique_string=f"{long_url}-{time.time()}-{uuid.uuid4()}"

    #hash the unique string using SHA 256
    hashed_bytes=hashlib.sha256(unique_string.encode("utf-8")).digest()

    #converting bytes to url safe format
    safe_encode_string=base64.urlsafe_b64encode(hashed_bytes).decode("utf-8")

    clean_string=safe_encode_string.replace('=','').replace('-','').replace('_','')

    return clean_string[:length]

async def verify_url_reachability(url:str)->bool:
    try:
        async with httpx.AsyncClient(timeout=3.0) as client:
            responce=client.head(url,follow_redirects=True)
            return responce<400

    except:
        return False

