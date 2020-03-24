// =========================================
// mLibrary macro 1.0
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
// and the books are stored in shelves above the closet
// There are nShelf shelves                   
// The height of each shelf is random
//  -----------------
// |                 |  Shelf 3
//  -----------------
// |                 |
// |                 |  Shelf 2
//  -----------------
// |                 |
// |                 |  Shelf 1
//  =================
// |XXXXXXXXXXXXXXXXX|
// |XXXXXXXXXXXXXXXXX|  Panel
// |XXXXXXXXXXXXXXXXX|
// |=================|
// |=================|  Plinth
//
// #declare xLib=1; // library width
// #declare yLib=3; // library height
// #declare zShelf=0.27; // depth of shelves
// #declare zLibShelf=0.3; // depth of the side planks (>zShelf)
// #declare zLibPanel=0.5; // depth of bottom panels  (>zLibShelf)
// #declare ePlankShelf=0.025; // thickness of shelf plank
// #declare yLibPanel=0.8; // height of bottom panel
// #declare yPlinth=0.2; // height of bottom plinth
// #declare nShelf=6; // number of shelves
// #declare sdyShelf=0.2;  // pseudo standard deviation of shelf height (-sdyShelf*h/2 to +sdShelf*h/2)
// #declare xBook=0.03;    // Book thickness
// #declare sdxBook=0.03;  // pseudo standard deviation of book thickness (-sdxBook*xBook/2 to +sdxBook*xBook/2)
// #declare sdyBook=0.04;  // pseudo standard deviation of book height
// #declare sdzBook=0.05;  // pseudo standard deviation of book depth
// #declare typeShelf=0;     // series
// #declare typeBook=0;     // old books
// #declare slackShelf=1;  // some slack
// #declare nSetMax=4;  // maximum number of book sets on the same shelf
// #declare doBooks=true; // creates the books
// #declare T_Library=texture{} // library texture (wood texture going up)

#macro mLibrary(xLib,yLib,zLibShelf,zLibPanel,yLibPanel,yPlinth,nShelf,sdyShelf,ePlankShelf,xBook,sdxBook,sdyBook,sdzBook,typeShelf,typeBook,slackShelf,nSetMax,doBooks,T_Lib)
#warning "Parsing Library\n"

#local ePlankSide=ePlankShelf*1.2; // thickness of side plank
#local ePlankTop=ePlankSide*2;     // thickness of top plank
#local xShelf=xLib-4*(ePlankSide);
#local xPlank=xLib-2*ePlankSide;
#local Plank=union{
        box{<0,0,-zShelf>,<xPlank,ePlankShelf,0>}
        cylinder{0,x*xPlank,ePlankShelf*0.5 scale <1,1,0.5> translate <0,ePlankShelf*0.5,-zShelf>}
}                      
#local yPanel=yLibPanel-ePlankTop-yPlinth;
#local xPanel=xLib-2*ePlankSide;
#local T_Libtmp=texture{T_Lib translate <1-rand(rd),1-rand(rd),1-rand(rd)>*xPanel*2}
union{  
        // far plank (closes the library)
        box{<0,0,-ePlankShelf/10>,<xLib,yLib,0> texture{T_Libtmp finish{ambient 0.01 diffuse 0.4 specular 0.2 roughness 0.01 }}}
        
        // library sides
        union{
                // left side plank, bottom
                box{<0,0,-zLibPanel>,<ePlankSide,yLibPanel,0>}
                cylinder{0,yLibPanel*y,ePlankSide*0.5 scale <1,1,0.5> translate <ePlankSide*0.5,0,-zLibPanel>}
                
                
                // right side plank, bottom
                box{<xLib-ePlankSide,0,-zLibPanel>,<xLib,yLibPanel,0>}
                cylinder{0,yLibPanel*y,ePlankSide*0.5 scale <1,1,0.5> translate <xLib-ePlankSide*0.5,0,-zLibPanel>}
                
                // left side plank, up (shelves)
                box{<0,yLibPanel,-zLibShelf>,<ePlankSide,yLib,0>}
                cylinder{yLibPanel*y,yLib*y,ePlankSide*0.5 scale <1,1,0.5> translate <ePlankSide*0.5,0,-zLibShelf>}
                
                // right side plank, up (shelves)
                box{<xLib-ePlankSide,yLibPanel,-zLibShelf>,<xLib,yLib,0>}
                cylinder{yLibPanel*y,yLib*y,ePlankSide*0.5 scale <1,1,0.5> translate <xLib-ePlankSide*0.5,0,-zLibShelf>}
                
                texture{T_Libtmp rotate y*90}
        }                                                               
        // top plank                                                                       
        union{
                box{<0,-ePlankTop/3,-zLibShelf-ePlankShelf>,<xLib,0,0>}
                cylinder{0,xLib*x,1 scale <1,ePlankTop/3,ePlankShelf> translate <0,-ePlankTop/3,-zLibShelf>} // baguette
                cylinder{0,xLib*x,1 scale <1,ePlankTop/6,ePlankShelf> translate <0,-5*ePlankTop/6,-zLibShelf>} // baguette
                translate y*yLib
                texture{T_Libtmp rotate z*90}
        }                       

        // top plank on bottom panel
        union{
                box{<0,0,-zLibPanel>,<xLib,ePlankTop,0>}
                cylinder{0,xLib*x,ePlankTop*0.25 scale <1,1,0.25> translate <0,ePlankTop*0.75,-zLibPanel>} // baguette
                translate y*(yLibPanel-ePlankTop)
                texture{T_Libtmp rotate z*90}
        }               
                                        
        // bottom plinth
        union{
                box{<0,0,-zLibPanel>,<xLib,yPlinth,0>}
                union{
                        cylinder{0,xLib*x,ePlankSide*0.5 translate y*(yPlinth-ePlankSide*0.5)}
                        cylinder{0,xLib*x,ePlankSide*0.5 translate y*ePlankSide*0.5}
                        translate -z*zLibPanel
                } 
                texture{T_Libtmp rotate z*90}
        }
        // inner casing of the library
        #local yLibShelf=yLib-yLibPanel-ePlankTop;
        union{
                box{<0,0,-zLibShelf>,<ePlankShelf,yLibShelf,0> translate <ePlankSide,yLibPanel,0>} // left
                box{<-ePlankShelf,0,-zLibShelf>,<0,yLibShelf,0> translate <xLib-ePlankSide,yLibPanel,0>} // right
                texture{T_Libtmp rotate y*90}
        }                                 
        union{
                box{<0,0,-zLibShelf>,<xLib-2*(ePlankSide+ePlankShelf),ePlankTop,0> translate <ePlankSide+ePlankShelf,yLibPanel,0>} // bottom (y=ePlankTop)
                box{<0,0,-zLibShelf>,<xLib-2*(ePlankSide+ePlankShelf),ePlankSide,0> translate <ePlankSide+ePlankShelf,yLib-ePlankTop-ePlankSide,0>} // top (y=ePlankside)
                texture{T_Libtmp rotate z*90}
        }
        
        // Panel
        union{
                // central panel
                box{0,<xPanel-2*(ePlankTop+3*ePlankShelf),yPanel-2*(ePlankTop+3*ePlankShelf),zLibPanel-3*ePlankShelf> translate <ePlankTop+3*ePlankShelf,ePlankTop+3*ePlankShelf,-zLibPanel+3*ePlankShelf> texture{T_Libtmp}}
//                #include "isopanel.inc"
                // sides                
                box{<0,0,-zLibPanel+ePlankShelf>,<xPanel,ePlankTop,0> texture{T_Libtmp rotate z*90}}
                box{<0,ePlankTop,-zLibPanel+ePlankShelf>,<ePlankTop,yPanel-ePlankTop,0> texture{T_Libtmp}}
                box{<xPanel-ePlankTop,ePlankTop,-zLibPanel+ePlankShelf>,<xPanel,yPanel-ePlankTop,0> texture{T_Libtmp}}
                box{<0,yPanel-ePlankTop,-zLibPanel+ePlankShelf>,<xPanel,yPanel,0> texture{T_Libtmp rotate z*90}}
                
                cylinder{0,x*xPanel,ePlankShelf translate <0,ePlankTop,-zLibPanel+2*ePlankShelf> texture{T_Libtmp rotate z*90}}
                cylinder{0,x*xPanel,ePlankShelf translate <0,yPanel-ePlankTop,-zLibPanel+2*ePlankShelf> texture{T_Libtmp rotate z*90}}
                cylinder{0,y*yPanel,ePlankShelf translate <ePlankTop,0,-zLibPanel+2*ePlankShelf> texture{T_Libtmp}}
                cylinder{0,y*yPanel,ePlankShelf translate <xPanel-ePlankTop,0,-zLibPanel+2*ePlankShelf> texture{T_Libtmp}}
                
                box{<0,0,-zLibPanel+2*ePlankShelf>,<xPanel,ePlankTop+ePlankShelf*2,0> texture{T_Libtmp rotate z*90}}
                box{<0,ePlankTop+2*ePlankShelf,-zLibPanel+2*ePlankShelf>,<ePlankTop+ePlankShelf*2,yPanel-ePlankTop-ePlankShelf*2,0> texture{T_Libtmp}}
                box{<xPanel-ePlankTop-ePlankShelf*2,ePlankTop+ePlankShelf*2,-zLibPanel+2*ePlankShelf>,<xPanel,yPanel-ePlankTop-ePlankShelf*2,0> texture{T_Libtmp}}
                box{<0,yPanel-ePlankTop-ePlankShelf*2,-zLibPanel+2*ePlankShelf>,<xPanel,yPanel,0> texture{T_Libtmp rotate z*90}}
                                    
                cylinder{0,x*xPanel,ePlankShelf translate <0,ePlankTop+2*ePlankShelf,-zLibPanel+3*ePlankShelf>  texture{T_Libtmp rotate z*90}}
                cylinder{0,x*xPanel,ePlankShelf translate <0,yPanel-ePlankTop-2*ePlankShelf,-zLibPanel+3*ePlankShelf> texture{T_Libtmp rotate z*90}}
                cylinder{0,y*yPanel,ePlankShelf translate <ePlankTop+2*ePlankShelf,0,-zLibPanel+3*ePlankShelf> texture{T_Libtmp}}
                cylinder{0,y*yPanel,ePlankShelf translate <xPanel-ePlankTop-2*ePlankShelf,0,-zLibPanel+3*ePlankShelf>  texture{T_Libtmp}}
        
                translate <ePlankSide,yPlinth,0>
        }
        
        // shelves and books
        #local yLibShelf=yLib-yLibPanel-ePlankTop*2-ePlankSide;
        #local i=0;
        #local yShelfPos=0;
        #while (i<nShelf)
                #if (i<nShelf-1)
                        #local yShelf=((yLibShelf-(nShelf-1)*ePlankShelf)/nShelf)+sdyShelf*(rand(rd)-0.5);
                #else
                        #local yShelf=yLibShelf-yShelfPos-ePlankShelf;
                #end
                #if (doBooks=true)
                        #declare nSet=1+int(nSetMax*rand(rd)); // number of sets
                        #declare yRow=yShelf*0.9;      // the row of books has to be smaller
                        // Here we create the bookshelf
                        #declare BookRow=object{mShelf(xShelf,yRow,zShelf,nSet,typeShelf,slackShelf,xBook,sdxBook,sdyBook,sdzBook)}
                        #if (i>0)
                                object{Plank translate <2*ePlankSide,yShelfPos,0> translate y*(yLibPanel+ePlankTop) texture{T_Libtmp rotate z*90}}
                                object{BookRow translate <2*ePlankSide,yShelfPos+ePlankShelf+yLibPanel+ePlankTop,0>}
                                #local yShelfPos=yShelfPos+yShelf+ePlankShelf;
                        #else
                                object{BookRow translate <2*ePlankSide,yLibPanel+ePlankTop,0>}
                                #local yShelfPos=yShelfPos+yShelf;
                        #end 
                #else
                        #if (i>0)
                                object{Plank translate <2*ePlankSide,yShelfPos,0> translate y*(yLibPanel+ePlankTop) texture{T_Libtmp rotate z*90}}
                                #local yShelfPos=yShelfPos+yShelf+ePlankShelf;
                        #else
                                #local yShelfPos=yShelfPos+yShelf;
                        #end 
                #end
                #local i=i+1;
        #end
        texture{T_Libtmp}
}
#warning "End Parsing Library\n"
#end

// -----------------------------------------
// end of mLibrary macro
// =========================================
