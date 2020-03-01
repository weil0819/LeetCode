/*

158. Read N Characters Given Read4 II - Call multiple times -- Hard
http://www.leetfree.com/problems/read-n-characters-given-read4-ii-call-multiple-times.html

The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. 
or example, it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

Note:
The read function may be called multiple times.

*/

// Forward declaration of the read4 API.
int read4(char *buf);
 
class Solution {
public:
    int read(char *buf, int n) {
        int i = 0;
        while(lastPos<lastLen && n-->0) buf[i++] = tem[lastPos++];	// if moving pointer doesn't reach end
        while(n > 0 && (lastLen = read4(tem)) > 0)	// read in lastLen chars, where lastLen should be larger than 0
        {
            lastPos = 0;							// moving pointer of tem
            while(lastPos < lastLen && n-- > 0) 	// scan each char in tem, where lastPos is a moving pointer
                buf[i++] = tem[lastPos++];			// put into buf
        }
        return i;									// return the number of chars read
    }

private:
    int lastPos = 0;	// moving pointer in tem
    int lastLen = 0;	// record the number of char read by read4() function
    char tem[4];		// store 4 chars which is read by read4() function
};




