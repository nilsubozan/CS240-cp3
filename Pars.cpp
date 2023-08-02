#include <iostream>
#include <string>
#include <fstream>
#include "Pars.h"
#include "Animal.h"
#include <vector>

#include <bits/stdc++.h>

using namespace std;

//to check if the seed is numeric
bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

Animal whwins(vector <Animal>& vec,int counter,const int lin, vector <Animal>& tem){
    //bubblesort
    //string first =obj1.getname();
    //string second = obj2.getname();
    Animal temp;
    //string comp[2]={first, second};

    if(vec.size()==1){
        return vec[0];
    }
    else{
        if(vec.size()==lin/2 || vec.size()==lin/4 ||vec.size()==lin/8 || vec.size()==lin/16 || vec.size()==lin/32){
            counter=0;
        }
        

        for(int i=counter; i<counter+1;i++){
            for(int j=counter+1;j<counter+2;j++){
                if(vec[i].getname()>vec[j].getname()){
                    temp= vec[i];
                    vec[i]=vec[j];
                    vec[j]=temp;
                }
            }
        }
        
       

        vec[counter].wincount+=1;
        for(int i=0;i<lin;i++){
            if(vec[counter].getname()==tem[i].getname()){
                tem[i].wincount+=1;
            }
        }
        cout<<vec[counter].getname() <<" "<<"("<<vec[counter].getRegion()<<" "<<vec[counter].getseed()<<") ["<<vec[counter].wincount<<" wins] defeats "<<vec[counter+1].getname()<<" ("<<vec[counter+1].getRegion()<<" "<<vec[counter+1].getseed()<<") ["<<vec[counter+1].wincount<<" wins]"<<endl;
        vec.erase(vec.begin()+(counter+1));
        counter+=1;
        return whwins(vec,counter,lin,tem);

    }

    
    /*
    if(vec[0]==obj1.getname()){
        //Winner is object in comp[0];
        obj1.wincount+=1;   
        return obj1;
    }
    
    else{
        obj2.wincount+=1;
        return obj2;
    }
    */
    
}

int main(int argc, char* argv[]){
    string line;
    string command;
    int powersof2 [9]= {1,2,4,8,16,32,64,127,256};

    if(argc>=2){
        vector <Animal> vect;
        Animal animal;
        int seednum;
        string checknumeric;
        ifstream infile(argv[1]);
        if(infile.is_open() && infile.good()){
            string line = " ";
            int linecount= 0;
            while(getline(infile, line)){
                Parser command(line);
                if(command.numArgs()<2){
                    //QUESTION: Should i still continue if there is missing args...
                    cout<<std::endl<< MISSING_ARGS <<endl; continue;
                }
                else if(command.numArgs()>2){
                    cout << std::endl << "Ignoring " << UNEXPECTED_ARGS << endl;
                }
                else if(command.numArgs()==2){
                    checknumeric=command.getArg2();
                    if(isNumber(checknumeric)==false){
                        cout<<"!!! Seed is not numeric"<<endl;
                        //QUESTION:What should i do if seed is not numeric? Skip to other line?
                        //Should i still store it in a vector?
                    }
                    else{
                        //if it is numeric, convert it to number and create an object
                        seednum = stoi(command.getArg2());
                        animal=Animal(command.getOperation(),command.getArg1(), seednum);
                        vect.push_back(animal);
                    }
                    linecount=linecount+1;
                }
            }
            int ispower= 0;
            for(int i = 0; i<9;i++){
                if(linecount==powersof2[i]){
                    ispower=1;
                    //means that number of teams is power of 2
                }
            }
            if(ispower==0){
                cout<< "!!! Number of teams should be power of 2"<<endl;
            }
            else if(ispower==1){
                for(int i=0; i<linecount; i++){
                    if(vect[i].getRegion()!="EAST" && vect[i].getRegion()!="WEST" && vect[i].getRegion()!="MIDWEST" && vect[i].getRegion()!="SOUTH"){
                        cout<<"Invalid Region on line "<< linecount<<endl;
                    }   
                }
                //for(int j=0; j<linecount; j++){
                  //  vect[j].printfunc();
               // }

                int ctr=0;
                vector <Animal> tem;
                for(int i=0;i<linecount;i++){
                    tem.push_back(vect[i]);
                }
                reverse(vect.begin(),vect.end());
                cout<<"------------"<<endl;
                cout<<"Tournament: "<<endl;
                cout<<"------------"<<endl;
                
                Animal resul= whwins(vect,ctr,linecount,tem);
                cout<<"------------"<<endl;
                cout<<"Winner: "<<endl;
                cout<<"------------"<<endl;
                cout<<resul.getname()<<" ("<<resul.getRegion()<<" "<< resul.getseed()<<") "<<"["<<resul.wincount<<" wins] is the winner!"<<endl;
                cout<<"------------"<<endl;
                cout<<"Stats: "<<endl;
                cout<<"------------"<<endl;
                
                for(int i=0;i<linecount;i++){
                    cout<<tem[i].getname() <<" "<<"("<<tem[i].getRegion()<<" "<<tem[i].getseed()<<") ["<<tem[i].wincount<<" wins]"<<endl;
                    

                }
                
                

            }
        }
    }
    else{   
        cout<< "File name is missing, program ended.";
        return 0;
    }


}