//===========================================================================================
// 640. Solve the Equation

// Solve a given equation and return the value of x in the form of string "x=#value". 
// The equation contains only '+', '-' operation, the variable x and its coefficient.

// If there is no solution for the equation, return "No solution".

// If there are infinite solutions for the equation, return "Infinite solutions".

// If there is exactly one solution for the equation, we ensure that the value of x is an integer.

// Example 1:
// Input: "x+5-3+x=6+x-2"
// Output: "x=2"
// Example 2:
// Input: "x=x"
// Output: "Infinite solutions"
// Example 3:
// Input: "2x=x"
// Output: "x=0"
// Example 4:
// Input: "2x+3x-6x=x+2"
// Output: "x=-1"
// Example 5:
// Input: "x=x+2"
// Output: "No solution"
//===========================================================================================

class Solution {
public:
	/**
	* Idea: No matter left or right side, we will get kx+z at last
	* 
	*/
    /*
    string solveEquation(string equation) {
        string res = "x=";
        int k = 0, z = 0, start = 0;
        for(int i = 0; i < equation.size(); i++){
        	if(equation[i] == 'x'){
        		int j = i-1, cnt = 1, tmp = 0;
        		while(j >= 0 && equation[j] != '+' && equation[j] != '-'){
        			tmp = (equation[j]-'0')*cnt + tmp;
        			cnt *= 10;
        			j--;
        		}
        		if(j < 0 || equation[j] == '+'){
        			k += (tmp == 0 ? 1 : tmp);
        		}else{
        			k -= (tmp == 0 ? 1 : tmp);
        		}
        	}else if(equation[i] == '+' || equation[i] == '-'){
        		if(equation[i-1] != 'x'){
        			int j = i-1, cnt = 1, tmp = 0;
        			while(equation[j] != '+' && equation[j] != '-'){
        				tmp = (equation[j]-'0')*cnt + tmp;
        				cnt *= 10;
        				j--;
        			}
        			if(j < 0 || equation[j] == '+'){
        				z += (tmp == 0 ? 1 : tmp);
        			}else{
        				z -= (tmp == 0 ? 1 : tmp);
        			}
        		}
        	}else if(equation[i] == '='){
        		start = i;
        		if(equation[i-1] != 'x'){
        			int j = i-1, cnt = 1, tmp = 0;
        			while(equation[j] != '+' && equation[j] != '-'){
        				tmp = (equation[j]-'0')*cnt + tmp;
        				cnt *= 10;
        				j--;
        			}
        			if(j < 0 || equation[j] == '+'){
        				z += (tmp == 0 ? 1 : tmp);
        			}else{
        				z -= (tmp == 0 ? 1 : tmp);
        			}
        		}                
        		break;
        	}
        }
        for(int i = start+1; i < equation.size(); i++){
        	if(equation[i] == 'x'){
        		int j = i-1, cnt = 1, tmp = 0;
        		while(j > start && equation[j] != '+' && equation[j] != '-'){
        			tmp = (equation[j]-'0')*cnt + tmp;
        			cnt *= 10;
        			j--;
        		}
        		if(j <= start || equation[j] == '+'){
        			k -= (tmp == 0 ? 1 : tmp);
        		}else{
        			k += (tmp == 0 ? 1 : tmp);
        		}
        	}else if(equation[i] == '+' || equation[i] == '-'){
        		if(equation[i-1] != 'x' && equation[i-1] != '='){
        			int j = i-1, cnt = 1, tmp = 0;
        			while(equation[j] != '=' && equation[j] != '+' && equation[j] != '-'){
        				tmp = (equation[j]-'0')*cnt + tmp;                       
        				cnt *= 10;
        				j--;                        
        			} 
        			if(equation[j] == '=' || equation[j] == '+'){
        				z -= (tmp == 0 ? 1 : tmp);
        			}else{
        				z += (tmp == 0 ? 1 : tmp);
        			}
        		}
        	}else if(i == equation.size()-1){
        		if(equation[i] != 'x'){
        			int j = i, cnt = 1, tmp = 0;
        			while(equation[j] != '=' && equation[j] != '+' && equation[j] != '-'){
        				tmp = (equation[j]-'0')*cnt + tmp;                       
        				cnt *= 10;
        				j--;                        
        			}    
        			if(equation[j] == '=' || equation[j] == '+'){
        				z -= (tmp == 0 ? 1 : tmp);
        			}else{
        				z += (tmp == 0 ? 1 : tmp);
        			}
        		}                
            }        	
        }
        if(k == 0 && z == 0){
        	return "Infinite solutions";
        }else if(k == 0 && z != 0){
        	return "No solution";
        }else{
        	int tmp = -z/k;
        	res = res + to_string(tmp);
        	return res;
        }        
    }
    */
    string solveEquation(string equation) {
        int n = equation.size(), sign = 1, k = 0, z = 0;
        int j = 0;
        for(int i = 0; i < n; i++){
            if(equation[i] == '+' || equation[i] == '-'){
                if(i > j){
                    z += sign*stoi(equation.substr(j, i-j));
                }
                j = i;
            }else if(equation[i] == 'x'){
                if((j == i) || equation[i-1] == '+'){
                    k += sign;
                }else if(equation[i-1] == '-'){
                    k -= sign;
                }else{
                    k += sign*stoi(equation.substr(j, i-j));
                }
                j = i+1;
            }else if(equation[i] == '='){
                if(i > j){
                    z += sign*stoi(equation.substr(j, i-j));     
                }
                sign = -1;
                j = i+1;
            }
        }
        // there may be a number in the end
        if(j < n){
            z += sign*stoi(equation.substr(j));
        }
        if(k == 0 && z == 0){
            return "Infinite solutions";
        }else if(k == 0 && z != 0){
            return "No solution";
        }else{
            int tmp = -z/k;
            string res = "x=" + to_string(tmp);
            return res;
        }         
    }
};
