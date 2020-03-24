// =========================================
// Demo file for the MakeLibrary suite / Old style books
// -----------------------------------------
// Made for Persistence of vision 3.6
//==========================================  
// Copyright 2004 Gilles Tran http://www.oyonale.com
// -----------------------------------------
// This work is licensed under the Creative Commons Attribution License. 
// To view a copy of this license, visit http://creativecommons.org/licenses/by/2.0/ 
// or send a letter to Creative Commons, 559 Nathan Abbott Way, Stanford, California 94305, USA.
// You are free:
// - to copy, distribute, display, and perform the work
// - to make derivative works
// - to make commercial use of the work
// Under the following conditions:
// - Attribution. You must give the original author credit.
// - For any reuse or distribution, you must make clear to others the license terms of this work.
// - Any of these conditions can be waived if you get permission from the copyright holder.
// Your fair use and other rights are in no way affected by the above. 
//==========================================  
// This macro creates a library and the books it contains
// The library is made of a panelled closet at the bottom of height yLibPanel
// Edit the "titles.txt" and "fonts.txt" files if necessary
// The items in these list MUST be separated with commas
// -----------------------------------------
/*#include "colors.inc"
camera{
    location  <2, 1.7, -14>   
//        location  <1.5, 3, -3.5>   
    direction 2.7*z  
    right 4*x/3  
    look_at   <2, 2, 0>
}
background{White}        
light_source{<-1,1,-1.5>*1000 color White*2}
      */
#include "EXT_MakeBook.inc"
#include "EXT_MakeShelf.inc"
#include "EXT_MakeLibrary.inc"

#declare rd=seed(0); // seed

#declare xLib=1.5; // library width
#declare yLib=4; // library height
#declare zShelf=0.3; // depth of shelves
#declare zLibShelf=0.3; // depth of the side planks (>zShelf)
#declare zLibPanel=0.5; // depth of bottom panels
#declare ePlankShelf=0.025; // thickness of shelf plank
#declare ePlankSide=0.03; // thickness of side plank
#declare ePlankTop=0.06; // thickness of top and main horizontal planks  
#declare yLibPanel=0.8; // height of bottom panel
#declare yPlinth=0.2; // height of bottom plinth
#declare sdyShelf=0.2;  // pseudo standard deviation of shelf height (-sdyShelf*h/2 to +sdShelf*h/2)
#declare xBook=0.08; // Book thickness
#declare sdxBook=0.03;  // pseudo standard deviation of book thickness (-sdxBook*xBook/2 to +sdxBook*xBook/2)
#declare sdyBook=0.08;  // pseudo standard deviation of book height
#declare sdzBook=0.06;  // pseudo standard deviation of book depth
#declare typeShelf=0;     // by series
#declare typeBook=0;     // old books
#declare slackShelf=0;  // no slack

#declare C_Wood=rgb<71,31,5>/255;
#declare T_Wood=texture{
        pigment{
                wood         
                turbulence 0.2
                lambda 3
                rotate x*-80
                rotate z*-20
                scale 0.1*<1,8,1>*0.7
                color_map{
                        [0 C_Wood*1.1]
                        [1 C_Wood*0.6]
                }
                        
        }        
        finish{ambient 0.01 diffuse 0.6 specular 0.4 roughness 0.01}
}        

                       