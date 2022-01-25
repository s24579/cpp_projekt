#include <iostream>
#include <random>
#include <stdio.h>
char mapa_widoczna[30][30]={};
int mapa[30][30]={};
int kolumna,wiersz; 
    //wypisuje pola w terminalu
    auto wypisanie_mapy() -> void
    {   
        std::cout << "   ";
        for(int i=0;i<30;i++)
        {   
            if(i<10)
            {
            std::cout << "\033[1;31m" << i <<"\033[0m" << "  ";
            }
            else
            {
            std::cout << "\033[1;31m" << i <<"\033[0m" << " "; 
            }
        }
        std::cout << std::endl;
        for(int i=0;i<30;i++)
        {   
            if(i<10)
            {
                std::cout << "\033[1;31m" << i <<"\033[0m" << "  ";
            }
            else
            {
            std::cout << "\033[1;31m" << i <<"\033[0m" " ";
            }
            for(int j=0;j<30;j++)
            {
             std::cout << mapa_widoczna[i][j] << "  ";
            }
            std::cout << std::endl;
        }
        
        return;
    }
    //wypisuje cyfry oznaczajace ile min otacza komorke
    auto dodanie_cyfr() -> void
    {   
        int kol,wier;
        //srodek mapy
        for(int i=1;i<29;i++)
        {
            for(int j=1;j<29;j++)
            {   
                if(mapa[i][j]==9)
                {   
                    kol=i-1;
                    wier=j-1;
                    for(int fl=0;fl<3;fl++)
                    {   
                        
                        for(int fl2=0;fl2<3;fl2++)
                        {   
                            if(mapa[kol][wier]!=9)
                            {
                                mapa[kol][wier]+=1;
                            }
                            kol++;
                        }
                        wier++;
                        kol=i-1;
                    }
                }
            }
        }
        //gorna krawedz
        for(int g=1;g<29;g++)
        {   
            int g2=g-1;
            if(mapa[0][g]==9)
            {   
                for(int i=0;i<3;i++)
                {
                    if(mapa[1][g2]!=9)
                    {
                        mapa[1][g2]+=1;
                    }
                    g2++;
                }
                g2=g-1;
                for(int i=0;i<2;i++)
                {
                    if(mapa[0][g2]!=9)
                    {
                        mapa[0][g2]+=1;
                    }
                    g2+=2;
                }
            }
        }
        //dolna krawedz
        for(int d=1;d<29;d++)
        {   
            int d2=d-1;
            if(mapa[29][d]==9)
            {   
                for(int i=0;i<3;i++)
                {
                    if(mapa[28][d2]!=9)
                    {
                        mapa[28][d2]+=1;
                    }
                    d2++;
                }
                d2=d-1;
                for(int i=0;i<2;i++)
                {
                    if(mapa[29][d2]!=9)
                    {
                        mapa[29][d2]+=1;
                    }
                    d2+=2;
                }
            }
        }
        //lewa krawedz
        for(int l=1;l<29;l++)
        {   
            int l2=l-1;
            if(mapa[l][0]==9)
            {   
                for(int i=0;i<3;i++)
                {
                    if(mapa[l2][1]!=9)
                    {
                        mapa[l2][1]+=1;
                    }
                    l2++;
                }
                l2=l-1;
                for(int i=0;i<2;i++)
                {
                    if(mapa[l2][0]!=9)
                    {
                        mapa[l2][0]+=1;
                    }
                    l2+=2;
                }
            }
        }
        //prawa krawedz
        for(int r=1;r<29;r++)
        {   
            int r2=r-1;
            if(mapa[r][29]==9)
            {   
                for(int i=0;i<3;i++)
                {
                    if(mapa[r2][28]!=9)
                    {
                        mapa[r2][28]+=1;
                    }
                    r2++;
                }
                r2=r-1;
                for(int i=0;i<2;i++)
                {
                    if(mapa[r2][29]!=9)
                    {
                        mapa[r2][29]+=1;
                    }
                    r2+=2;
                }
            }
        }
        //4 rogi mapy
        if(mapa[0][0]==9)
        {
            if(mapa[1][0]!=9)
            {
            mapa[1][0]+=1;
            }
            if(mapa[1][1]!=9)
            {
            mapa[1][1]+=1;
            }
            if(mapa[0][1]!=9)
            {
            mapa[0][1]+=1;
            }        
        }
        if(mapa[29][29]==9)
        {
            if(mapa[29][28]!=9)
            {
            mapa[29][28]+=1;
            }
            if(mapa[28][29]!=9)
            {
            mapa[28][29]+=1;
            }
            if(mapa[28][28]!=9)
            {
            mapa[28][28]+=1;
            }
        }
        if(mapa[0][29]==9)
        {   
            if(mapa[0][28]!=9)
            {
            mapa[0][28]+=1;
            }
            if(mapa[1][28]!=9)
            {
            mapa[1][28]+=1;
            }
            if(mapa[1][29]!=9)
            {
            mapa[1][29]+=1;
            }
        }
        if(mapa[29][0]==9)
        {
            if(mapa[28][0]!=9)
            {
            mapa[28][0]+=1;
            }
            if(mapa[28][1]!=9)
            {
            mapa[28][1]+=1;
            }
            if(mapa[29][1]!=9)
            {
            mapa[29][1]+=1;
            }
        } 
        for(int i=0;i<30;i++)
        {
            for(int j=0;j<30;j++)
            {
                mapa_widoczna[i][j]='_';
            }
        }
    }
    auto wypisanie_kropek() -> void
    {   
        int kol,wier;
        //srodek mapy
        for(int i=1;i<29;i++)
        {
            for(int j=1;j<29;j++)
            {   
                if(mapa[i][j]==0)
                {   
                    kol=i-1;
                    wier=j-1;
                    for(int fl=0;fl<3;fl++)
                    {   
                        
                        for(int fl2=0;fl2<3;fl2++)
                        {   
                            if(mapa[kol][wier]==0)
                            {
                                mapa_widoczna[kol][wier]='.';
                            }
                            kol++;
                        }
                        wier++;
                        kol=i-1;
                    }
                }
            }
        }
        //gorna krawedz
        for(int g=1;g<29;g++)
        {   
            int g2=g-1;
            if(mapa[0][g]==0)
            {   
                for(int i=0;i<3;i++)
                {
                    if(mapa[1][g2]==0)
                    {
                        mapa_widoczna[1][g2]='.';
                    }
                    g2++;
                }
                g2=g-1;
                for(int i=0;i<2;i++)
                {
                    if(mapa[0][g2]==0)
                    {
                        mapa_widoczna[0][g2]='.';
                    }
                    g2+=2;
                }
            }
        }
        //dolna krawedz
        for(int d=1;d<29;d++)
        {   
            int d2=d-1;
            if(mapa[29][d]==0)
            {   
                for(int i=0;i<3;i++)
                {
                    if(mapa[28][d2]==0)
                    {
                        mapa_widoczna[28][d2]='.';
                    }
                    d2++;
                }
                d2=d-1;
                for(int i=0;i<2;i++)
                {
                    if(mapa[29][d2]==0)
                    {
                        mapa_widoczna[29][d2]='.';
                    }
                    d2+=2;
                }
            }
        }
        //lewa krawedz
        for(int l=1;l<29;l++)
        {   
            int l2=l-1;
            if(mapa[l][0]==0)
            {   
                for(int i=0;i<3;i++)
                {
                    if(mapa[l2][1]==0)
                    {
                        mapa_widoczna[l2][1]='.';
                    }
                    l2++;
                }
                l2=l-1;
                for(int i=0;i<2;i++)
                {
                    if(mapa[l2][0]==0)
                    {
                        mapa_widoczna[l2][0]='.';
                    }
                    l2+=2;
                }
            }
        }
        //prawa krawedz
        for(int r=1;r<29;r++)
        {   
            int r2=r-1;
            if(mapa[r][29]==0)
            {   
                for(int i=0;i<3;i++)
                {
                    if(mapa[r2][28]==0)
                    {
                        mapa_widoczna[r2][28]='.';
                    }
                    r2++;
                }
                r2=r-1;
                for(int i=0;i<2;i++)
                {
                    if(mapa[r2][29]==0)
                    {
                        mapa_widoczna[r2][29]='.';
                    }
                    r2+=2;
                }
            }
        }
        //4 rogi mapy
        if(mapa[0][0]==0)
        {
            if(mapa[1][0]==0)
            {
            mapa_widoczna[1][0]='.';
            }
            if(mapa[1][1]==0)
            {
            mapa_widoczna[1][1]='.';
            }
            if(mapa[0][1]==0)
            {
            mapa_widoczna[0][1]='.';
            }        
        }
        if(mapa[29][29]==0)
        {
            if(mapa[29][28]==0)
            {
            mapa_widoczna[29][28]='.';
            }
            if(mapa[28][29]==0)
            {
            mapa_widoczna[28][29]='.';
            }
            if(mapa[28][28]==0)
            {
            mapa_widoczna[28][28]='.';
            }
        }
        if(mapa[0][29]==0)
        {   
            if(mapa[0][28]==0)
            {
            mapa_widoczna[0][28]='.';
            }
            if(mapa[1][28]==0)
            {
            mapa_widoczna[1][28]='.';
            }
            if(mapa[1][29]==0)
            {
            mapa_widoczna[1][29]='.';
            }
        }
        if(mapa[29][0]==0)
        {
            if(mapa[28][0]==0)
            {
            mapa_widoczna[28][0]='.';
            }
            if(mapa[28][1]==0)
            {
            mapa_widoczna[28][1]='.';
            }
            if(mapa[29][1]==0)
            {
            mapa_widoczna[29][1]='.';
            }
        } 
        
    }
    //losuje pozycje bomb
    auto bomby() -> void
    {   
        std::random_device rd;
        std::uniform_int_distribution<int>random(0,29);
        kolumna=random(rd);
        wiersz=random(rd);
        for(int x=0;x<15;)
        {   
            if(mapa[kolumna][wiersz]==0)
            {   
                mapa[kolumna][wiersz]=9;
                x++;
            }
            else
            {
                kolumna=random(rd);
                wiersz=random(rd);
            }
        }
    }
    //przeprowadza gre
    auto gra() -> void
    {   
        int bomby_es=0;
        bool game_over=false;
        int x,y;
        char action;
        int licznik_bomb=0;
        while (!game_over)
        {  
            licznik_bomb=0;
            bomby_es=0;
            wypisanie_mapy();
            std::cout << std::endl << "P - odsloniecie pola" << std::endl << "Z - oznaczenie miny" << std::endl << "F - zdjecie oznaczenia miny";
            std::cout << std::endl << "Wypisz nr wiersza, nr kolumny i akcje" << std::endl;
            std::cin >> x >> y >> action;
            if(action=='P')
            {
            if(mapa[x][y]==0)
            {
                wypisanie_kropek();
            }
            if(mapa[x][y]==1)
            {
                mapa_widoczna[x][y]='1';
            }
            if(mapa[x][y]==2)
            {
                mapa_widoczna[x][y]='2';
            }
            if(mapa[x][y]==3)
            {
                mapa_widoczna[x][y]='3';
            }
            if(mapa[x][y]==4)
            {
                mapa_widoczna[x][y]='4';
            }
            if(mapa[x][y]==5)
            {
                mapa_widoczna[x][y]='5';
            }
            if(mapa[x][y]==6)
            {
                mapa_widoczna[x][y]='6';
            }
            if(mapa[x][y]==7)
            {
                mapa_widoczna[x][y]='7';
            }
            if(mapa[x][y]==8)
            {
                mapa_widoczna[x][y]='8';
            }
            if(mapa[x][y]==9)
            {
                for(int i=0;i<30;i++)
                {
                    for(int j=0;j<30;j++)
                    {   
                        if(mapa[i][j]==9&&mapa_widoczna[i][j]=='X')
                        {
                            mapa_widoczna[i][j]='+';
                        }
                        else if(mapa[i][j]==9&&mapa_widoczna[i][j]!='+')
                        {
                            mapa_widoczna[i][j]='*';
                        }
                    }
                }
                wypisanie_mapy();
                game_over=true;
                std::cout << "GAME OVER" << std::endl;
            }
            }
            if(action=='Z')
            {
                mapa_widoczna[x][y]='X';
            }
            if(action=='F'&&mapa_widoczna[x][y]=='X')
            {
                mapa_widoczna[x][y]='_';
            }
            for(int x=0;x<30;x++)
            {
                for(int y=0;y<30;y++)
                {
                    if(mapa_widoczna[x][y]=='X')
                    {
                        licznik_bomb+=1;
                    }
                }
            }
            for(int x=0;x<30;x++)
            {
                for(int y=0;y<30;y++)
                {
                    if(mapa_widoczna[x][y]=='X'&&mapa[x][y]==9)
                    {
                        bomby_es+=1;
                    }
                }
            }    
            if(bomby_es==15)
            {   
                wypisanie_mapy();
                game_over=true;
                std::cout << "YOU WIN" << std::endl;
            }
            if(game_over==false)
            {
            std::cout << std::endl << "\033[0;34m" << "POZOSTALE MINY: " << "\033[0;34m" << 15-licznik_bomb << std::endl;
            }
        }
        
        
    }
auto main() ->int 
{
    bomby();
    dodanie_cyfr();
    gra();
    return 0;
}
