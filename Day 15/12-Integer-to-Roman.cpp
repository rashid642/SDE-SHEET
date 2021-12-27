class Solution {
public:
    string intToRoman(int num) {
        string s;
        while(num){
            if(num>=1000){
                s = s+"M";
                num -= 1000;
                continue;
            }
            if(num>=900){
                s = s+"CM";
                num -= 900;
                continue;
            }
            if(num>=500){
                s += "D";
                num -= 500;
                continue;
            }
            if(num>=400){
                s += "CD";
                num -= 400;
                continue;
            }
            if(num>=100){
                s += "C";
                num -= 100;
                continue;
            }
            if(num>=90){
                s += "XC";
                num -= 90;
                continue;
            }
            if(num>=50){
                s += "L";
                num -= 50;
                continue;
            }
            if(num>=40){
                s += "XL";
                num -= 40;
                continue;
            }
            if(num>=10){
                s += "X";
                num -= 10;
                continue;
            }
            if(num>=9){
                s += "IX";
                num -= 9;
                continue;
            }
            if(num>=5){
                s += "V";
                num -= 5;
                continue;
            }
            if(num>=4){
                s += "IV";
                num -= 4;
                continue;
            }
            else{
                s += "I";
                num -= 1;
            }
        }
        return s;
    }
};