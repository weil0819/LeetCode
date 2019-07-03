//===========================================================================================
// 12. Integer to Roman

// Given an integer, convert it to a roman numeral.

// Input is guaranteed to be within the range from 1 to 3999.
//===========================================================================================

class Solution {
public:
	/**
	* Idea: There are 7 roman numbers: I(1)V(5)X(10)L(50)C(100)D(500)M(1000)
	* Firstly, num - 1000, then num - 500, ...
	* we need pay attention to some special numbers, such like 
	*			IV(4), IX(9), XL(40), XC(90), CD(400), CM(900)
	* 
	*/
    string intToRoman(int num) {
        string res = "";
        while(num > 0){
        	if(num >= 1000){
        		num = num - 1000;
        		res.append("M");
        	}else if(num >= 900 && num < 1000){
        		num = num - 900;
        		res.append("CM");
        	}else if(num >= 500 && num < 900){
        		num = num - 500;
        		res.append("D");
        	}else if(num >= 400 && num < 500){
        		num = num - 400;
        		res.append("CD");
        	}else if(num >= 100 && num < 400){
        		num = num - 100;
        		res.append("C");
        	}else if(num >= 90 && num < 100){
        		num = num - 90;
        		res.append("XC");
        	}else if(num >= 50 && num < 90){
        		num = num - 50;
        		res.append("L");
        	}else if(num >= 40 && num < 50){
        		num = num - 40;
        		res.append("XL");
        	}else if(num >= 10 && num < 40){
        		num = num - 10;
        		res.append("X");
        	}else if(num == 9){
        		num = num - 9;
        		res.append("IX");
        	}else if(num >= 5 && num < 9){
        		num = num - 5;
        		res.append("V");
        	}else if(num == 4){
        		num = num - 4;
        		res.append("IV");
        	}else if(num >= 1 && num < 4){
        		num = num - 1;
        		res.append("I");
        	}
        }
        return res;
    }
};