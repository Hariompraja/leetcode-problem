class Solution {
public:
    string simplifyPath(string path) {

        path+='/';
        stack<string> my_Stack;
    
        string current="";


        for(char &ch:path){

            if(ch=='/'){
                if(current=="."){  
                    current = "";
                    continue;
                }
                if(current==".."){
            
                    if(!my_Stack.empty())
                         my_Stack.pop();

                    current="";
                    continue;
                }
                if(current!="")
                my_Stack.push(current);

                current="";
            }else{
                current+=ch;
            }
        }

        stack<string> my_New;
    
        while(!my_Stack.empty()){
            my_New.push(my_Stack.top());     
            my_Stack.pop();
        }
        string ans="";
        while(!my_New.empty()){
            ans+=('/'+my_New.top());
            my_New.pop();
        }
        if(ans=="")return "/";

        return ans;
    }
};