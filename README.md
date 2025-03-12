# Suugaku - 数学ライブラリ

## 概要

Suugaku は、C++ で数学関連の計算を簡単に行うためのライブラリです。標準ライブラリ `cmath` にない便利な関数を追加し、三角関数、素数判定、階乗計算、乱数生成などを提供します。

## 必要な環境

本ライブラリを使用するには、以下の開発環境が必要です。

- **C/C++ コンパイラ**
  - GCC (g++)
  - Clang
  - MSVC など
- **C++ 標準ライブラリ** (C++11 以降推奨)
- **C 標準ライブラリ** (`stdio.h`, `stdlib.h` などを使用)

## インストール方法

1. `suugaku.h` をプロジェクトフォルダに追加します。
2. `#include "suugaku.h"` をソースコードに記述します。
3. C++ コンパイラでコンパイルします。

```cpp
#include "suugaku.h"
#include <iostream>

int main() {
    std::cout << "5の階乗: " << suugaku::fact(5) << std::endl;
    return 0;
}
```

コンパイル例（G++ の場合）:

```sh
g++ -o main main.cpp
./main
```

---

## 関数の説明(Verison 4から)

### 1. `triangle` - 三角関数関連

| 関数名                | 説明                     | 例                                        |
| ------------------ | ---------------------- | ---------------------------------------- |
| `sin_deg(x)`       | `x` 度の `sin` 値を返す      | `suugaku::triangle::sin_deg(30); // 0.5` |
| `cos_deg(x)`       | `x` 度の `cos` 値を返す      | `suugaku::triangle::cos_deg(60); // 0.5` |
| `tan_deg(x)`       | `x` 度の `tan` 値を返す      | `suugaku::triangle::tan_deg(45); // 1.0` |
| `asin_ratio(a, c)` | `a/c` から `sin` の角度を求める | `suugaku::triangle::asin_ratio(1, 2);`   |
| `acos_ratio(b, c)` | `b/c` から `cos` の角度を求める | `suugaku::triangle::acos_ratio(1, 2);`   |
| `atan_ratio(a, b)` | `a/b` から `tan` の角度を求める | `suugaku::triangle::atan_ratio(1, 1);`   |
| `coslaw(a, b,C)` | 余弦定理で特定の辺の長さを求める。※`C`は角度 です。 | `suugaku::triangle::coslaw(1, 1,90); //1.414....`   |

---

### 1.5. `triangle::pythagoras` - 三平方関連

| 関数名                | 説明                     | 例                                        |
| ------------------ | ---------------------- | ---------------------------------------- |
| `strtri_a(b,c)`       | 直角三角形のaの長さを返す      | `suugaku::triangle::pythagoras::strtri_a(1.73,2); // 1` |
| `strtri_b(a,c)`       | 直角三角形のbの長さを返す      | `suugaku::triangle::pythagoras::strtri_b(1,2); // 1.73...` |
| `strtri_c(a,b)`       | 直角三角形のcの長さを返す      | `suugaku::triangle::pythagoras::strtri_c(1,1); // 1.414....` |

---

### 2. `nature` - 数学的性質の判定

| 関数名            | 説明                    | 例                                         |
| -------------- | --------------------- | ----------------------------------------- |
| `is_even(n)`   | `n` が偶数なら `true` を返す  | `suugaku::nature::is_even(4); // true`    |
| `is_odd(n)`    | `n` が奇数なら `true` を返す  | `suugaku::nature::is_odd(5); // true`     |
| `is_prime(n)`  | `n` が素数なら `true` を返す  | `suugaku::nature::is_prime(7); // true`   |
| `is_square(n)` | `n` が平方数なら `true` を返す | `suugaku::nature::is_square(16); // true` |
| `is_cube(n)`   | `n` が立方数なら `true` を返す | `suugaku::nature::is_cube(27); // true`   |
| `is_fibo(n)`   | `n` がフィボナッチ数なら `true` を返す | `suugaku::nature::is_fibo(8); // true`   |

---

### 3. `random` - 乱数生成

| 関数名                  | 説明                                 | 例                                   |
| -------------------- | ---------------------------------- | ----------------------------------- |
| `rand_int(min, max)` | `min` から `max` の範囲の乱数を生成           | `suugaku::random::rand_int(1, 10);` |
| `rand_mt(min, max)`  | `min` から `max` の範囲の乱数を mt19937 で生成 | `suugaku::random::rand_mt(1, 10);`  |

---

### 4. その他の数学関数

| 関数名             | 説明              | 例                                          |
| --------------- | --------------- | ------------------------------------------ |
| `fact(n)`       | `n!` (階乗) を計算   | `suugaku::fact(5); // 120`                 |
| `prime_fact(n)` | `n#` 以下の素数の階乗を計算 | `suugaku::prime_fact(7); // 210 (2*3*5*7)` |
| `to_radian(x)`  | `x` 度をラジアンに変換   | `suugaku::to_radian(180); // 3.1415...`    |
| `pi()`          | 40 桁以上の円周率を返す   | `suugaku::pi();`                           |

---

## ライセンス
MIT License に基づき自由に使用できます。

