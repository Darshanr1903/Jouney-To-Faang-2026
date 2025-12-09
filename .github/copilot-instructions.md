# AI Coding Agent Instructions for Journey to FAANG 2026

## Project Overview
This repository is a **Data Structures & Algorithms (DSA) practice project** for FAANG interview preparation. The codebase consists of C++ competitive programming solutions organized by month and day of study.

## Repository Structure

- `Month1_work_track/` - Contains daily DSA practice problems
  - `DAY0.cpp` - Example: simple array sorting solution

## Development Conventions

### Code Style & Patterns
- **Language**: C++ with competitive programming conventions
- **Headers**: Use `#include <bits/stdc++.h>` (non-standard but standard in competitive programming)
- **Standard Practice**: Using `using namespace std;` for competitive context
- **Code Organization**: Each file contains a single solution with main() entry point

### Typical Solution Structure
```cpp
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Read input
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Solve problem
    sort(arr.begin(), arr.end());
    
    // Output result
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
```

## Debugging & Testing Setup

- **Debug Configuration**: `.vscode/launch.json` includes GDB attach configuration for Windows
- **Compiler Expected**: GCC/G++ with GDB debugger support
- **Build Approach**: Individual .cpp files should compile and run independently

## Key Conventions to Follow

1. **Problem-Solving Focus**: Each file represents one problem/concept
2. **Input/Output Handling**: Use standard cin/cout for I/O
3. **Algorithm Implementation**: Prioritize clarity and correctness over optimization in learning phase
4. **Common Data Structures**: STL containers (vector, map, set, queue, etc.)

## When Adding New Solutions

- Create files in appropriate `MonthX_work_track/` directory
- Use descriptive filenames: `DAY{number}_{concept}.cpp` or problem name
- Include comments explaining the approach for non-trivial algorithms
- Test with sample inputs before committing

## Compilation & Execution
Individual files can be compiled with:
```bash
g++ -o solution DAY0.cpp
./solution
```

---

**Note**: This is a learning/preparation repository. Code prioritizes clarity and educational value over production-ready practices.
