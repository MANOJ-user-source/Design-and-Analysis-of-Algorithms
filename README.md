# Design and Analysis of Algorithms

| | |
|---|---|
| **Name** | Manoj Tiwari Ramchandra |
| **Course** | BCA Semester 4 |
| **Subject** | Design and Analysis of Algorithms (DAA) |

---

## Lab Practicals

| # | Problem | Best Time Complexity | Status |
|---|---------|----------------------|--------|
| 01 | [Smallest Divisor of an Integer](Practical_01_Smallest_Divisor/) | O(√n) | Done |
| 02 | [Generate Prime Numbers ≤ n](Practical_02_Prime_Numbers/) | O(n log log n) | Done |

---

## Repository Structure

```
Design-and-Analysis-of-Algorithms/
├── README.md
├── Practical_01_Smallest_Divisor/
│   └── smallest_divisor.cpp
├── Practical_02_Prime_Numbers/
│   └── prime_numbers.cpp
└── ...
```

---

## Getting Started

### 1. Install C++ Compiler (Windows)

**Download MinGW-w64:**
- https://github.com/niXman/mingw-builds-binaries/releases

**Setup:**
1. Extract to `C:\mingw64`
2. Add `C:\mingw64\bin` to System PATH:
   - Press `Win + S` → Search "Environment Variables"
   - Edit System Variables → Path → Add `C:\mingw64\bin`

**Verify:**
```bash
g++ --version
```

### 2. Compile and Run

```bash
cd Practical_01_Smallest_Divisor
g++ smallest_divisor.cpp -o smallest_divisor.exe
./smallest_divisor.exe
```

| Action | Command |
|--------|---------|
| Compile | `g++ file.cpp -o file.exe` |
| Run | `./file.exe` |

---

## Complexity Reference

| Notation | Name | Example |
|----------|------|---------|
| O(1) | Constant | Array access |
| O(log n) | Logarithmic | Binary search |
| O(n) | Linear | Linear search |
| O(n log n) | Linearithmic | Merge sort |
| O(n²) | Quadratic | Bubble sort |
| O(2ⁿ) | Exponential | Recursive Fibonacci |

---

> BCA Semester 4 | Design and Analysis of Algorithms Lab
