class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        int top;
        int sectop;
        for(int i =0; i<tokens.size();i++){
            if(isdigit(tokens[i][0])){
                nums.push(stoi(tokens[i]));
                //need to handle negatives
            } else if (tokens[i][0]=='-' && tokens[i].length()>1){
                int x = stoi(tokens[i].substr(1,tokens[i].length()-1)) * -1;
                nums.push(x);
            } else {
                top=nums.top();
                nums.pop();
                sectop = nums.top();
                nums.pop();  
                if(tokens[i] == "+"){
                    nums.push(sectop + top);                                      
                } else if(tokens[i] == "-"){
                    nums.push(sectop - top);  
                } else if(tokens[i] == "/"){
                    nums.push(sectop / top);  
                } else if(tokens[i] == "*"){
                    nums.push(sectop * top);
                }
            }
        }
        top = nums.top();
        return top;
    }
};