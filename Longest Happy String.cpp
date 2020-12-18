class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string s="";
        pair<int,char> A[3];
        A[0]=make_pair(a, 'a');
        A[1]=make_pair(b, 'b');
        A[2]=make_pair(c, 'c');
        
        while(1){
            int p=0;
            sort(A, A+3);
            if(A[2].first==0) break;
            
            if(s.size()==0 || s.size()==1){
                s.push_back(A[2].second);
                A[2].first--;
                p=1;
            }
            else if(s[s.size()-1]==A[2].second && s[s.size()-2]==A[2].second){
                if(A[1].first==0) break;
                else{
                    s.push_back(A[1].second);
                    A[1].first--;
                    p=1;
                }
            }
            else{
                s.push_back(A[2].second);
                A[2].first--;
                p=1;
            }
            
            if(p==0) break;
        }
        return s;
        
    }
};
