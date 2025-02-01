#ifndef SUUGAKU_H
#define SUUGAKU_H

/*
ver 1.0 2025/2/1
数学ライブラリです暇だから作りました。
cmathにはなかったけどほしかった関数を作りました～！
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define RADIAN(x) (x*3.1415926535/180)


double PI_SUUGAKU = 3.1415926535897932384626433832795028841971;


namespace suugaku{

    namespace triangle{
        
        /*
        @brief 直角三角形のsinの角度に対する比を返します 
        @brief suugaku::triangle::get_sin(直角三角形の角度)
        */
        double get_sin(float x){
            return sin(RADIAN(x));
        }

        /*
        @brief 直角三角形のcosの角度に対する比を返します 
        @brief suugaku::triangle::get_sin(直角三角形の角度)
        */
        double get_cos(float x){
            return cos(RADIAN(x));
        }

        /*
        @brief 直角三角形のtamの角度に対する比を返します 
        @brief suugaku::triangle::get_tan(直角三角形の角度)
        */
        double get_tan(float x){
            return tan(RADIAN(x));
        }


        /*
        @brief 直角三角形の三角関数の対応する比から角度を演算して値を返します。
        @brief suugaku::triangle::getan_sin(直角三角形のa,直角三角形のc)
        */
        double getan_sin(float a,float c){
            double ans = (a/c);
            return asin(ans)*180/3.1415926535;
        }

        /*
        @brief 直角三角形の三角関数の対応する比から角度を算出して値を返します。
        @brief suugaku::triangle::getan_cos(直角三角形のb,直角三角形のc)
        */
        double getan_cos(float b,float c){
            double ans = (b/c);
            return acos(ans)*180/3.1415926535;
        }

        /*
        @brief 直角三角形の三角関数の対応する比から角度を算出して値を返します。
        @brief suugaku::triangle::getan_tan(直角三角形のa,直角三角形のb)
        */
        double getan_tan(float a,float b){
            double ans = (a/b);
            return atan(ans)*180/3.1415926535;
        }

    }


    namespace nature{
        
        /*@brief 与えられた値が偶数ならばtrueを返します。*/
        bool Even(int x){
            if (x%2 == 0) return true;
            else return false;
        }

        /*@brief 与えられた値が奇数ならばtrueを返します。*/
        bool Odd(int x){
            if (x%2 != 0) return true;
            else return false;
        }

    }
    
    /*
      @brief 整数の指定範囲の乱数の値を返します。
      @brief suugaku::su_rand(最小値,最大値)
    */
    int su_rand(int min,int max){
        static int set_srand;

        if (set_srand == 0){
            srand((signed int)time(NULL));
            set_srand = 1;
        }

        return min + (rand() % (max - min + 1));
    }
    
    /*
    @brief 階上(n!)を計算してその値を返します。
    */
    long long exlam(int x){
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
    @brief 与えられた値のラジアンを返します。
    @brief suugaku::getRAD(角度)
    */
    double getRAD(float x){
        return RADIAN(x);
    }

    /*
    @brief 40桁以上の円周率の値を返します
    */
    double getPI(){
        return PI_SUUGAKU;
    }

}


#endif