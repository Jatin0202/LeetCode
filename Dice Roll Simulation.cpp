class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<long long>> S[n];
        long long i,j,k,ans=0,mod=1000000007;
        for(i=0;i<n;i++) {
            vector<vector<long long>> current;
            for(j=0;j<6;j++){
                vector<long long> P;
                for(k=0;k<rollMax[j];k++){
                    P.push_back(0);
                }
                current.push_back(P);
            }
            S[i]= current;
        }
        S[0][0][0]=S[0][1][0]=S[0][2][0]=S[0][3][0]=S[0][4][0]=S[0][5][0]= 1;
        
        for(i=1;i<n;i++){
            for(j=0;j<6;j++){
                for(k=0;k<rollMax[j];k++){
                    if(k==0){
                        ans= 0;
                        for(int j1=1;j1<6;j1++){
                            for(int k1=0;k1<rollMax[(j1+j)%6];k1++){
                                ans= (ans+S[i-1][(j1+j)%6][k1]+mod)%mod;
                            }
                        }
                        
                        S[i][j][k]= (ans+mod)%mod;
                    }
                    else{
                        S[i][j][k]= (S[i-1][j][k-1]+mod)%mod;
                    }
                }
            }
            
            
        }
        if(1){
            i = n-1;
            ans= 0;
            for(j=0;j<6;j++){
                for(k=0;k<rollMax[j];k++) ans= (ans+S[i][j][k]+mod)%mod;
            }
        }
        
        
        
        return (ans+mod)%mod;
    }
};