/*

157. Read N Characters Given Read4 -- Easy
https://www.leetfree.com/problems/read-n-characters-given-read4.html

The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. 
For example, it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) 
that reads n characters from the file.

Note:
The read function will only be called once for each test case.

*/

/*
用Read4 API读取N个字符

首先，只要N > 0，定义字符数组tmp，调用read4()读取4个字符到tmp中，并记录读取字符的长度
然后，顺序遍历上面读取的字符串，把它放入buf

*/

// Forward declaration of the read4 API.
int read4(char *buf);
 
class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
    	int res = 0, len = 0;
    	char tmp[4];				// define an array to store the buffer in read4()	
    	while(n > 0 && (len = read4(tmp)) > 0){
    		int i = 0;
    		while(i < len && n-- > 0){
    			buf[res++] = tmp[i++];	// output buf
    		}
    	}
    	return res;
    }
};

