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

//C++ library
#include <iostream>
#include <cmath>
#include <random>
#include <ctime>

//C library
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define RADIAN(x) (x*3.1415926535/180)


const double PI_SUUGAKU = 3.1415926535897932384626433832795028841971;

namespace suugaku{

    namespace triangle{
        
        /*
        @brief 直角三角形のsinの角度に対する比を返します 
        */
        double sin_deg(float x){
            return sin(RADIAN(x));
        }

        /*
        @brief 直角三角形のcosの角度に対する比を返します 
        */
        double cos_deg(float x){
            return cos(RADIAN(x));
        }

        /*
        @brief 直角三角形のtamの角度に対する比を返します 
        */
        double tan_deg(float x){
            return tan(RADIAN(x));
        }


        /*
        @brief 直角三角形の三角関数の対応する比から角度を演算して値を返します。
        */
        double asin_ratio(float a,float c){
            double ans = (a/c);
            return asin(ans)*180/3.1415926535;
        }

        /*
        @brief 直角三角形の三角関数の対応する比から角度を算出して値を返します。
        */
        double acos_ratio(float b,float c){
            double ans = (b/c);
            return acos(ans)*180/3.1415926535;
        }

        /*
        @brief 直角三角形の三角関数の対応する比から角度を算出して値を返します。
        */
        double atan_ratio(float a,float b){
            double ans = (a/b);
            return atan(ans)*180/3.1415926535;
        }

    }


    namespace nature{
        
        /*@brief 与えられた値が偶数ならばtrueを返します。*/
        bool is_even(int x){
            if (x%2 == 0) return true;
            else return false;
        }

        /*@brief 与えられた値が奇数ならばtrueを返します。*/
        bool is_odd(int x){
            if (x%2 != 0) return true;
            else return false;
        }

        /*@brief 与えられた値が素数ならtrueを返します。*/
        bool is_prime(int x){
            if (x<2) return false;
            
            for(int i = 2; i < x; i++){
                if(x%i == 0) return false;
            }

            return true;
        }

        /*@brief 与えられた値が平方数ならばtrueを返します。 */
        bool is_square(int Sqrt_num){
            int ans = sqrt(Sqrt_num);
            return pow(ans,2) == Sqrt_num;
        }

        /*@brief 与えられた値が立方数ならばtrueを返します。 */
        bool is_cube(int Cbrt_num){
            int ans = cbrt(Cbrt_num);
            return pow(ans,3) == Cbrt_num;
        }

    }

    namespace random{
        /*
        @brief 整数の指定範囲の乱数の値を返します。
        */
        int rand_int(int min,int max){
            static int set_srand;
            if (set_srand == 0){
                srand((signed int)time(NULL));
                set_srand = 1;
            }
            return min + (rand() % (max - min + 1));
        }

        /*@brief mt11937を使って整数範囲の乱数を生成します。*/
        int rand_mt(int min, int max){
            std::mt19937 rd(static_cast<unsigned int>(time(0)));
            std::uniform_int_distribution<int> hani(min,max);

            return hani(rd);
        }
    }
    
    /*
    @brief 階乗(n!)を計算してその値を返します。
    */
    long long fact(int x){
        long long kaijyou = 1;
        if (x == 0){
            return kaijyou;
        }else{
            for (int i = 1; i <= x; i++){
                kaijyou *= i;
            }
        }

        return kaijyou;
    }
    
    /* 
        @brief 与えられた値の素数階乗(n#)を演算して値を返します。
    */
    long long prime_fact(int x){
        long long result = 1;

        auto sosuu = [](int x) -> bool {
            if (x<2) return false;
            for(int i = 2; i < x; i++){
                if(x%i == 0) return false;
            }
            return true;
        };
        
        for(int i = 1; i < x; i++){
            if(sosuu(i)) result *= i;
        }

        return result;
    }

    /*
    @brief 与えられた値のラジアンを返します。
    */
    double to_radian(float x){
        return RADIAN(x);
    }

    /*
    @brief 40桁以上の円周率の値を返します
    */
    double pi(){
        return PI_SUUGAKU;
    }

}


#endif
