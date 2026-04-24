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

