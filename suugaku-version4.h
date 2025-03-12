#ifndef SUUGAKU_H
#define SUUGAKU_H

/*
ver 1.0 2025/2/1
数学ライブラリです暇だから作りました。
cmathにはなかったけどほしかった関数を作りました～！
*/

/*
ver 2.0 2025/2/7
素数階乗と素数判定のプログラムを作成しました。
*/

/*
ver 3.14 2025/3/5
ぬわぁぁぁんもう疲れたもぉぉぉん

すべての関数名の更新を行いました。
そのほかは平方数と立方数、判別をするbool型
関数の追加mt19937を使った乱数関連の関数を作り、
名前空間randomに乱数関連の関数をまとめまあした。
*/

/*
ver 4.0 2025/3/12

三平方の定理、余弦定理、フィボナッチ数の判定に関する関数を
追加しました。その他は関数のコメントを一部修正しました。

*/


//C++ library
#include <iostream>
#include <cmath>
#include <random>
#include <ctime>

//C library
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RADIAN(x) (x*3.1415926535/180)

const double PI_SUUGAKU = 3.1415926535897932384626433832795028841971;

namespace suugaku{

    namespace triangle{

        namespace pythagoras{
            /*
                @brief 三平方の定理を使って直角三角形のaの長さを求めます 
            */
            double strtri_a(float b,float c){
                return std::sqrt(-pow(b,2)+std::pow(c,2));
            }

            /*
                @brief 三平方の定理を使って直角三角形のbの長さを求めます 
            */
            double strtri_b(float a,float c){
                return std::sqrt(-pow(a,2)+std::pow(c,2));
            }

            /*
                @brief 三平方の定理を使って直角三角形のcの長さを求めます 
            */
            double strtri_c(float a,float b){
                return std::sqrt(pow(a,2)+std::pow(b,2));
            }
        }

        /*
            @brief 余弦定理を使って三角形の長さを求めます 
        */
        double coslaw(float a,float b,float C){
            return std::sqrt(pow(a,2) + pow(b,2) - 2*a*b * std::cos(RADIAN(C)));
        }
        
        /*
        @brief 直角三角形のsinの角度に対する比を返します 
        */
        double sin_deg(float x){
            return std::sin(RADIAN(x));
        }

        /*
        @brief 直角三角形のcosの角度に対する比を返します 
        */
        double cos_deg(float x){
            return std::cos(RADIAN(x));
        }

        /*
        @brief 直角三角形のtamの角度に対する比を返します 
        */
        double tan_deg(float x){
            return std::tan(RADIAN(x));
        }


        /*
        @brief 直角三角形の三角関数の対応する比から角度を演算して値を返します。
        */
        double asin_ratio(float a,float c){
            double ans = (a/c);
            return std::asin(ans)*180/3.1415926535;
        }

        /*
        @brief 直角三角形の三角関数の対応する比から角度を算出して値を返します。
        */
        double acos_ratio(float b,float c){
            double ans = (b/c);
            return std::acos(ans)*180/3.1415926535;
        }

        /*
        @brief 直角三角形の三角関数の対応する比から角度を算出して値を返します。
        */
        double atan_ratio(float a,float b){
            double ans = (a/b);
            return std::atan(ans)*180/3.1415926535;
        }

    }


    namespace nature{
        
        /*@brief 与えられた値(n)が偶数ならばtrueを返します。*/
        bool is_even(int n){
            if (n%2 == 0) return true;
            else return false;
        }

        /*@brief 与えられた値(n)が奇数ならばtrueを返します。*/
        bool is_odd(int n){
            if (n%2 != 0) return true;
            else return false;
        }

        /*@brief 与えられた値(n)が素数ならtrueを返します。*/
        bool is_prime(int n){
            if (n<2) return false;
            
            for(int i = 2; i < n; i++){
                if(n%i == 0) return false;
            }

            return true;
        }

        /*@brief 与えられた値(n)が平方数ならばtrueを返します。 */
        bool is_square(int n){
            int ans = sqrt(n);
            return std::pow(ans,2) == n;
        }

        /*@brief 与えられた値(n)が立方数ならばtrueを返します。 */
        bool is_cube(int n){
            int ans = cbrt(n);
            return std::pow(ans,3) == n;
        }

        /*@brief 与えられた値(n)がフィボナッチ数ならばtrueを返します。 */
        bool is_fibo(int n){
            int fi = 5 * pow(n,2);
            auto sqware_num = [](int sqnum) -> bool {
                int ans = sqrt(sqnum);
                return std::pow(ans,2) == sqnum;
            };

            return sqware_num(fi+4) || sqware_num(fi-4);
        }

    }

    namespace random{
        /*@brief 与えられた値(min~max)の範囲からの乱数を生成します。*/
        int rand_int(int min,int max){
            static int set_srand;
            if (set_srand == 0){
                srand((signed int)time(NULL));
                set_srand = 1;
            }
            return min + (rand() % (max - min + 1));
        }

        /*@brief mt11937を使って整数範囲(int~max)の乱数を生成します。*/
        int rand_mt(int min, int max){
            std::mt19937 rd(static_cast<unsigned int>(time(0)));
            std::uniform_int_distribution<int> hani(min,max);

            return hani(rd);
        }
    }
    
    /*
    @brief 階上(n!)を計算してその値を返します。
    */
    long long fact(int n){
        long long kaijyou = 1;
        if (n == 0){
            return kaijyou;
        }else{
            for (int i = 1; i <= n; i++){
                kaijyou *= i;
            }
        }

        return kaijyou;
    }
    
    /* 
        @brief 与えられた値の素数階乗(n#)を演算して値を返します。
    */
    long long prime_fact(int n){
        long long result = 1;

        auto sosuu = [](int x) -> bool {
            if (x<2) return false;
            for(int i = 2; i < x; i++){
                if(x%i == 0) return false;
            }
            return true;
        };
        
        for(int i = 1; i < n; i++){
            if(sosuu(i)) result *= i;
        }

        return result;
    }

    /*
    @brief 与えられた角度(n)のラジアンを返します。
    */
    double to_radian(float n){
        return RADIAN(n);
    }

    /*
    @brief 40桁以上の円周率の値を返します
    */
    double pi(){
        return PI_SUUGAKU;
    }

}


#endif
