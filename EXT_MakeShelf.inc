// =========================================
// mShelf macro 1.1
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
// This macro creates a book shelf where the books lean towards each other : \\\\
// The shelf extends on the x axis, the backs of the books point towards the -z axis
// The shelf is divided in "sets" ; each set leans towards the left or the right, alternatively
// The "reverse" set (///) is actually an inverted normal set (\\\) translated of the set length
// 
//  \\\\\\///////\\\\\\\///////
//  Set 1  Set 2  Set 3  Set 4
//
// xShelf : length of the shelf (the true length will be slightly shorter)
// yShelf : height of the shelf
// zShelf : depth of the shelf
// nBook : number of books
// nSet   : number of succeding book "sets" (each set leans to the opposite of the previous one)
// typeShelf : 0 = each set is made of identical books, 1 = each book is different
// slackShelf : controls the "slackness" of the books (0 = all books are strickly vertical)
// xBook, sdxBook : average and pseudo standard deviation of book thickness
// sdyBook : pseudo standard deviation of book height
// sdzBook : pseudo standard deviation of book depth
// 
// -----------------------------------------
// Notes
// -----------------------------------------
// Randomness : if you don't declare a seed before launching the macro, it will default to rd=seed(0)
// To obtain different shelves, put #declare rd=seed(0) before the macro (see example)
// -----------------------------------------
// The shelf is contained in the box :
// box{<0,0,-(zBook+sdzBook*0.6)>,<xShelf,(yBook+sdyBook*0.5)*cos(atan2(xBook+sdxBook*0.5,yBook+sdyBook*0.5))+(xBook+sdxBook*0.5)*sin(atan2(xBook+sdxBook*0.5,yBook+sdyBook*0.5)),0>}
// -----------------------------------------
// The formulas are geometrically right (I hope), but this macro doesn't take
// into account the weight of the books, so it can behave strangely sometimes
// -----------------------------------------
// Declare the font path and names before using this file.
// For example :
// #declare fontpath="\windows\fonts\\"
// #declare fontname_1="arial.ttf"
// #declare fontname_2="times.ttf"
// -----------------------------------------

#macro mShelf(xShelf,yShelf,zShelf,nSet,typeShelf,slackShelf,xBook,sdxBook,sdyBook,sdzBook)
#ifndef (rd) #declare rd=seed(0); #end // a seed must be declared
#local i=0;         
#local ixSetTrue=0; // current true set length
#local xShelfTrue=0; // current trut shelf length
#if (rand(rd)<0.5)
        #local sideLean=0; // lean to the left at the beginning
#else 
        #local sideLean=1; // lean to the right at the beginning
#end
union{
// shelf loop
#while (i<nSet) // i = set number
        // book set loop : all book lean to the left but the first
        #if (typeShelf=0) // if the type of shelf is set to "series" : all books are equal for this set
                // -------------------------------------------
                // Creation of book (series)
                // -------------------------------------------
                #local xB=xBook+sdxBook*(rand(rd)-0.5);
                #if (xB<=0) #local xB=xBook; #end
                #local yB=yShelf-sdyBook*rand(rd);
                #local zB=zShelf-sdzBook*rand(rd);
//                #local Book=mBook(xB,yB,zB)                  
                #local typePattern=int(rand(rd)*11+0.0001);
                #local Book=mBook(xB,yB,zB,typeBook,typePattern)
        #end
        
        union{ // set loop
                #local j=0; // j = book number in the set
                #local ixSet_tmp=0; 
                #local xShelfTrue=xShelfTrue+ixSetTrue; // true current length of the shelf
        
                #if (i=nSet-1)
                        #local ixSet=xShelf-xShelfTrue; // last set is adjusted to the self length
                #else                             
                        #local ixSet=(xShelf/nSet)*(1.5-rand(rd));  // set length is randomized
                #end
        
                #while (ixSet_tmp<ixSet) // progression along the set length
                //#warning concat(str(i,0,0)," ",str(j,0,0)," ",str(ixSet_tmp,0,3)," ",str(ixSet,0,3),"\n")
                        #local lMax=rand(rd)*slackShelf;
                        #if (typeShelf != 0) // all books are different
                                // -------------------------------------------
                                // Creation of book (full random)
                                // -------------------------------------------
                                #local xB=xBook+sdxBook*(rand(rd)-0.5);
                                #if (xB<=0) #local xB=xBook; #end
                                #local yB=yShelf-sdyBook*rand(rd);
                                #local zB=zShelf-sdzBook*rand(rd);
                //                #local Book=mBook(xB,yB,zB)                  
                                #local typePattern=int(rand(rd)*11+0.0001);
                                #local Book=mBook(xB,yB,zB,typeBook,typePattern)
                        #end                                                     
                        // -------------------------------------------
                        // Calculation of book placing parameters posB and aB
                        // -------------------------------------------
                        #if (j=0) // the first book of a set is always straight
                                #local posB=0;
                                #local aB=0;
                        #else     // following books                   
                                #local lB=cos(radians(aB_old))+lMax*rand(rd); // distance from the previous book
                                #local posB=posB_old+xB_old*lB;
                                // -------------------------------------------
                                // Calculation of book angle aB
                                // The solution was supposed to be straightforward but
                                // it took me 2 days to figure it out !
                                // -------------------------------------------
                                #if (lB>1/cos(radians(aB_old))) // present book leans on the previous one
                                        #local dA=posB-posB_old-xB_old/cos(radians(aB_old));
                                        #local dB=yB;
                                        #local dR=yB_old+xB_old*tan(radians(aB_old));
                                        #local dQ=sin(radians(aB_old))*dR;                            
                                        #if (dA*dA*(dQ*dQ-dR*dR)+dB*dB*dR*dR>=0)
                                                #local dX=(-(dQ*dA)+sqrt(dA*dA*(dQ*dQ-dR*dR)+dB*dB*dR*dR))/dR;
                                                
                                                #if (dX<dR) // present book leans on the previous book's cover
                                                        #local aB=90-degrees(acos(((dX*dQ/dR)+dA)/dB));
                                                #else       // present book leans on the previous book's top corner
                                                        #local aB=90-degrees(atan2(dR*cos(radians(aB_old)),(dQ+dA)));
                                                #end
                                        #else
                                                #local aB=0; // strange case, happens sometimes
                                        #end
                                        
                                #else // present book does not lean on the previous one but is held by its bottom corner  
                                        #if (slackShelf=0)   // no slack, all books are vertical
                                                #local aB=0;
                                        #else
                                                #local aB=degrees(atan2(lB-cos(radians(aB_old)),sin(radians(aB_old))));
                                        #end
                                #end
                                // -------------------------------------------
                                // End of calculation of book angle aB
                                // -------------------------------------------
                        #end
                        #if (posB+xB*cos(radians(aB))<=ixSet) // there's still room on the set
                        // -------------------------------------------
                        // This is where the books are placed
                        // -------------------------------------------   
                                
                                object{Book
                                        #if (sideLean=1) // invert on x axis ; necessary to invert the box textures if any
                                                scale <-1,1,1>
                                                translate x*xB
                                        #end
                                        rotate z*aB     // box is rotated to the left (aB positive)
                                        translate x*posB // box is translated to the right on the x axis
                                        translate -z*zB  // box is aligned on z=0 (far wall of the shelf)
                                } 
                                
                                sphere{0,0.01 pigment{Black} translate <-100+xB,-100,-100>}
                                #local j=j+1;
                                #local xB_old=xB;
                                #local yB_old=yB;
                                #local zB_old=zB;
                                #local aB_old=aB;
                                #local posB_old=posB;
                                #local ixSetTrue=posB+xB*cos(radians(aB)); // current "true" length of the set
                        #end
                        #local ixSet_tmp=posB+xB*cos(radians(aB));
                #end
        //      box{0,<3,4,2> pigment{Red} translate x*ixSetTrue} // This is a bookend !
                #if (sideLean=0) // lean on the left
                        translate x*xShelfTrue
                        #local sideLean=1;
                #else           // lean on the right, by inverting the object
                        scale <-1,1,1>
                        translate x*(xShelfTrue+ixSetTrue)
                        #local sideLean=0;
                #end
        //        #warning concat("end ",str(ixSetTrue,0,3),"\n")
        }                         
        
#local i=i+1;
#end
}
#end
// -----------------------------------------
// End of mShelf macro
// =========================================

/*
#macro mBook(xB,yB,zB)
        box{0,<xB,yB,zB> pigment{rgb <rand(rd),rand(rd),rand(rd)>}}
#end
*/
