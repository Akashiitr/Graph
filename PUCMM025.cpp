#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int p[50001];

int main()
{
    int a = 1;p[0] = 1;
    for(int i = 1; i <= 50000; i++)
    {
        p[i] = ( p[i-1] * (10%7) ) % 7;
    }
    char str[50001];
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",str);
        int num[10] = {0};
        int temp = 0;
        int size = strlen(str) ;
        for(int i = 0; i < size; i++){
            num[str[i]-48]++;
            temp = temp + str[i]-48;
        }
        bool d25 = 0;
        bool div[10] = {0};
        int ans = 0;

        div[0] = 0;

        div[1] = 1;

        if((str[size-1]-48) % 2 ==0)div[2]=1;

        if(temp % 3 == 0)div[3] = 1;

        if(temp % 9 == 0)div[9] = 1;

        if(size == 1){if(str[0] % 4 == 0)div[4] = 1;}
        else{
            temp = (str[size-1]-48) + (str[size-2]-48)*10;
            if(temp % 4 == 0 && size >= 2)div[4] = 1;
        }

        if(str[size-1] == '5'|| str[size-1] == '0')div[5] = 1;

        if(div[2]&&div[3])div[6] = 1;

        if(size == 1){if(str[0] == '8' || str[0] == '0')div[8] = 1;}
        else{
            temp = (str[size-1]-48) + (str[size-2]-48)*10;
            if(size == 2){if(temp % 8 == 0)div[8] = 1;}
            else{
                temp = (str[size-1]-48) + (str[size-2]-48)*10 + (str[size-3]-48)*100;
                if(temp % 8 == 0)div[8] = 1;
            }
        }


        int temp1 = 0, arg = 1;
        for(int i = 0; i < size; i++){
            temp1 = temp1 + (str[i]-48)*p[size -i -1];
            temp1 = temp1 % 7;
        }
        //cout << temp1 << endl;
        if(temp1%7 == 0)div[7] = 1;
        //cout << div[7] << endl;
        for(int i = 1; i <= 9; i++)
        {
            if(div[i]) ans = ans + num[i];
        }


        if(size == 1)d25 = 0;
        else{
            temp = (str[size-1]-48) + (str[size-2]-48)*10;
            if(temp % 25 == 0)d25 = 1;
        }

        //printf("%d\n",ans);
        //cout << d25 << endl;
        bool c252 = 0, c525 = 0;
        if(div[4] && div [7] && div [9])c252 = 1;
        if(div[3] && div[7] && d25)c525 = 1;
        if(c252)cout << "Yes ";
        else cout << "No ";
        if(c525) cout << "Yes"<<endl;
        else cout << "No"<<endl;
    }
}
