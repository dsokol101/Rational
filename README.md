# Rational Class

A C++ `Rational` class (fractions) demonstrating **operator overloading**. This is the code from class.

## Files

| File | Description |
|------|-------------|
| `Rational.h` | Class declaration |
| `Rational.cpp` | Class implementation (arithmetic and comparison operators) |
| `app.cpp` | Sample program (`main`) |

## Operator Overloading

In Java, a binary operation such as addition is written as a method:

```java
public Rational add(Rational other) {
    // get common denominator
    int den = this.den * other.den;
    int num = this.num * other.den + other.num * this.den;

    return new Rational(num, den);
}
```

Calling it with two `Rational` objects, `r1` and `r2`:

```java
Rational r3 = r1.add(r2);
```

In C++, you can overload the `+` operator so the same operation reads naturally:

```cpp
Rational r3 = r1 + r2;
```

## Supported Operators

- Arithmetic: `+`, `-`, `*`, `/`
- Comparison: `<`, `>`, `<=`, `>=`, `==`, `!=`

## Build and Run

```powershell
g++ -g3 -std=c++17 app.cpp Rational.cpp -o app.exe
./app.exe
```

## Debugging in VS Code

Set a breakpoint, then press **F5** and choose **Debug Rational (GDB)**. The program is rebuilt with debug symbols and launched under GDB so you can inspect the call stack and variables.
