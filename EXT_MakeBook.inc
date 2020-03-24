// =========================================
// mBook macro 1.2
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
// This macro creates a closed book
// The book is enclosed in the box {<0,0,0>,<xBook,yBook,zBook>}
// The book has a title chosen randomly in the "titles.txt" file and its title is
// written in a font chosen randomly in the "fonts.txt file.
// typeBook=0 creates old style books, with rounded binding, dark colors and gold trim
// typeBook=1 creates modern style books, with flat binding and funky colors
// flatratio is the flatness of the binding (this variable is set by the typeBook variable)
// -----------------------------------------
// Notes
// -----------------------------------------
// Randomness : if you don't local a seed before launching the macro, it will default to rd=seed(0)
// #local rd=seed(0) before the macro is used
// -----------------------------------------
// This macro requires a list of titles and a list of fonts
// The titles are stored in "titles.txt"
// The fonts are stored in "fonts.txt"
// You can add as many titles and fonts as you want provided that you separate them with commas
// -----------------------------------------

// =========================================
// Initialises the title list
// -----------------------------------------
#declare nTitles=0;
#fopen fTitles "EXT_titles.txt" read // list of book titles
#while (defined(fTitles)) // read once to get the number of titles
        #read(fTitles,dummy)
        #declare nTitles=nTitles+1;
#end
#fclose fTitles

#declare bookTitles=array[nTitles]   // List of titles
#declare bookTitlesLength=array[nTitles] // List of title length
#declare i=0;
#fopen fTitles "EXT_titles.txt" read // second to put the titles and their length into an array
#while (defined(fTitles))
        #read(fTitles,dummy)
        #declare bookTitles[i]=dummy 
        #declare bookTitlesLength[i]=strlen(dummy);
        #declare i=i+1;
#end
#fclose fTitles

// =========================================
// Initialises the font list
// -----------------------------------------
#declare nFonts=0;
#fopen fFonts "EXT_fonts.txt" read
#while (defined(fFonts))
        #read(fFonts,dummy)
        #declare nFonts=nFonts+1;
#end
#fclose fFonts
#declare bookFonts=array[nFonts]
#declare i=0;
#fopen fFonts "EXT_fonts.txt" read
#while (defined(fFonts))
        #read(fFonts,dummy)
        #declare bookFonts[i]=dummy
        #declare i=i+1;
#end
#fclose fFonts

// =========================================
// mBook macro 1.2
// -----------------------------------------
#macro mBook(xBook,yBook,zBook,typeBook,typePattern)
#ifndef (rd) #declare rd=seed(0); #end // a seed must be declared
#local C_Book=array[6]{Red,Red,Red,Red,Red,Red}
#local eCover=xBook/20; // thickness of the cover
union{    
        // -------------------------------------------
        // Book types
        // -------------------------------------------
        #switch (typeBook)
        // -------------------------------------------
        #case (0) // old book
        // -------------------------------------------
                #local flatratio=0.3+(0.3*rand(rd));                  
                #local C_Book[0]=rgb <1+0.3*rand(rd),0.3+0.3*rand(rd),0.2*rand(rd)>*0.2; // dark red
                #local C_Book[1]=rgb <0.2+0.5*rand(rd),0.8+0.3*rand(rd),0.4*rand(rd)>*0.2; // dark green
                #local C_Book[2]=rgb <0.858824+0.2*rand(rd),0.576471+0.2*rand(rd), 0.439216+0.2*rand(rd)>*0.3 ; //flesh
                #local C_Book[3]=rgb <1.2+0.2*rand(rd),0.1+0.2*rand(rd),0.2*rand(rd)>*0.4; // dark red
                #local C_Book[4]=rgb <1.3+0.2*rand(rd),1+0.2*rand(rd),0.2+0.5*rand(rd)>*0.5; // light brown
                #local C_Book[5]=rgb<1+rand(rd)*0.2,1+rand(rd)*0.2,rand(rd)*0.2>*0.8; // gold color
                
                #local C_Page=rgb<0.9+0.1*rand(rd),0.8+0.1*rand(rd),0.8>; // yellowish
                
                #local F_Cover=finish{metallic brilliance 3 ambient 0.01 diffuse 0.4 specular 0.3 roughness 0.1}
                #local F_Page=finish{ambient 0.1 diffuse 0.5 specular 0.1 roughness 0.1}
                #local C_Dom=C_Book[max(0,int(rand(rd)*5-0.001))];  
                #local C_Trim_1=C_Book[max(0,int(rand(rd)*3-0.001))];
                #local C_Trim_2=C_Book[5];                     
                #local P_Binder=mpatBinder(typePattern,C_Dom,C_Trim_1,C_Trim_2)
                #local T_Cover=texture{pigment{color C_Dom} finish{F_Cover}}
                #local T_Binding=texture{
                       pigment{P_Binder}
                       finish{F_Cover}
                       scale <xBook,yBook,yBook>
                }
                #local T_Title=texture{
                        pigment{color C_Book[5]}
                        finish{F_Cover}
                }
                #local T_Page=texture{
                        pigment{
                                gradient x
                                turbulence 0.1
                                color_map{
                                        [0 color C_Page]
                                        [1 color C_Page*0.7]
                                }
                        }
                        finish{F_Page}
                        scale xBook*rand(rd)*0.06
                        translate x*xBook
                }
        #break
        // -------------------------------------------
        #case (1) // modern book
        // -------------------------------------------
                #switch (rand(rd))        
                        #range (0,0.2)
                                #local C_Book_1=White*1.5;
                        #break
                        #range (0.2,0.3)
                                #local C_Book_1=Black;
                        #break
                        #else
                                #local C_Book_1=rgb <rand(rd),rand(rd),rand(rd)>;
                #end
                #local C_Book_2=rgb <rand(rd),rand(rd),rand(rd)>*2;        
                #switch (rand(rd))        
                        #range (0,0.3)
                                #local C_Title=White*2;
                        #break
                        #range (0.3,0.6)
                                #local C_Title=Black;
                        #break
                        #else
                                #local C_Title=rgb <1-C_Book_1.x,1-C_Book_1.y,1-C_Book_1.z>;
                #end
                #local flatratio=rand(rd)*0.2;
                #local C_Page=rgb<0.9+0.1*rand(rd),0.9+0.1*rand(rd),0.9>*1.1;
                #local F_Cover=finish{ambient 0.1 diffuse 0.4 specular 0.4 roughness 0.01}
                #local F_Page=finish{ambient 0.1 diffuse 0.5 specular 0.1 roughness 0.1}
                #local T_Cover=texture{
                        pigment{brick color C_Book_1,color C_Book_2 brick_size <1+rand(rd),1+rand(rd),1+rand(rd)> mortar rand(rd)}
                       finish{F_Cover}
                       scale yBook*rand(rd)
                       translate y*yBook*rand(rd)
                }
                #local T_Title=texture{
                        pigment{color C_Title}
                        finish{F_Cover}
                }
                #local T_Binding=texture{
                        pigment{
                                gradient y
                                color_map{
                                        [0 color C_Book_2]
                                        [0.3 color C_Book_2]
                                        [0.3 color C_Book_1]
                                        [1.0 color C_Book_1]
                                        }
                                }
                       finish{F_Cover}
                       scale yBook*(1+rand(rd))
                       translate y*yBook*(3+(rand(rd)))
                       
                }
                #local T_Page=texture{
                        pigment{
                                gradient x
                                turbulence 0.1
                                color_map{
                                        [0 color C_Page]
                                        [1 color C_Page*0.7]
                                }
                        }
                        finish{F_Page}
                        scale xBook*rand(rd)*0.06
                        translate x*xBook
                }
        #break
        // -------------------------------------------
        #else // single random color and random flatness
        // -------------------------------------------
                #local flatratio=rand(rd);
                #local C_Book_1=rgb <rand(rd),rand(rd),rand(rd)>;
                #local C_Book_2=rgb <1-C_Book_1.x,1-C_Book_1.y,1-C_Book_1.z>;
                #switch (rand(rd))        
                        #range (0,0.3)
                                #local C_Title=White*2;
                        #break
                        #range (0.3,0.6)
                                #local C_Title=Black;
                        #break
                        #else
                                #local C_Title=C_Book_2;
                #end
                #local C_Page=rgb<0.9+0.1*rand(rd),0.9+0.1*rand(rd),0.9+0.1*rand(rd)>*1.1;
                #local F_Cover=finish{ambient 0.1 diffuse 0.4 specular 0.4 roughness 0.01}
                #local F_Page=finish{ambient 0.1 diffuse 0.5 specular 0.1 roughness 0.1}
                #local T_Cover=texture{
                        pigment{color C_Book_1}
                        finish{F_Cover}
                }
                #local T_Title=texture{
                        pigment{color C_Title}
                        finish{F_Cover}
                }
                #local T_Binding=texture{
                        pigment{color C_Book_1}
                        finish{F_Cover}
                }
                #local T_Page=texture{
                        pigment{C_Page}
                        finish{F_Page}
                }
        #end
        // -------------------------------------------
        // Book parameters
        // -------------------------------------------
        #local rCover=eCover*0.5; // radius of cover thickness
        #local rBinding=xBook*0.5;  // radius of binding
        #local zBinding=rBinding*flatratio; // thickness of binding
        #local zCover=zBook-rCover-zBinding;
        #local yCover=yBook-eCover;
        #local zPage=zCover-4*eCover;
        #local yPage=yBook-4*eCover;
        #local xPage=xBook-2*eCover;

        // -------------------------------------------
        // front cover
        // -------------------------------------------
        union{
                box{0,<eCover,yCover,zCover>}          
                union{
                        cylinder{0,z*zCover,rCover translate <0,yCover,0>}
                        cylinder{0,z*zCover,rCover translate <0,0,0>} 
/*                          
                        cylinder{0,y*yCover,rCover translate z*zCover}
                        sphere{0,rCover translate <0,0,zCover>}
                        sphere{0,rCover translate <0,yCover,zCover>}
*/                        
                        translate x*rCover
                }                                     
                translate <rBinding-eCover,rCover,zBinding>
        }
        // -------------------------------------------
        // back cover
        // -------------------------------------------
        union{
                box{0,<eCover,yCover,zCover>}          
                union{
                        cylinder{0,z*zCover,rCover translate <0,yCover,0>}
                        cylinder{0,z*zCover,rCover translate <0,0,0>}
/*                        
                        cylinder{0,y*yCover,rCover translate z*zCover}
                        sphere{0,rCover translate <0,0,zCover>}
                        sphere{0,rCover translate <0,yCover,zCover>}
*/                        
                        translate x*rCover
                }                                     
                translate <rBinding-eCover,rCover,zBinding>
                scale <-1,1,1>
        }          
        
        // -------------------------------------------
        // binding
        // -------------------------------------------
        union{
                // -------------------------------------------
                // Book title on the binding
                // This part needs to be rewritten for use with the text functions in Megapov
                // -------------------------------------------   
                #if (typeBook=0) 
                        #local titleSize=0.4+0.3*rand(rd);
                #else 
                        #local titleSize=0.7+0.3*rand(rd);
                #end
                #local iBook=int(rand(rd)*nTitles);
                #local rtext=bookTitles[iBook]
                #local nLetters=bookTitlesLength[iBook]/1.8;
                #local titleBook=
                        text{ttf bookFonts[rand(rd)*nFonts] rtext 1,0
                        translate <-nLetters/2,-0.3,0>
                        scale <yBook*0.8*titleSize/nLetters,min(yBook*0.8*titleSize/nLetters,xBook),rCover>
                }
                
                object{titleBook rotate z*90 translate <0,yBook/2,zBinding-rBinding*flatratio> texture{T_Title}}
                
                difference{               
                        union{
                                cylinder{0,y*yCover,rBinding}
                                torus{rBinding-rCover,rCover sturm}
                                torus{rBinding-rCover,rCover  sturm translate y*yCover}
                        }
                        cylinder{-rCover*2*y,y*(yCover+rCover)*1.1,rBinding-eCover}
                        plane{z,0 inverse}                
                        scale <1,1,flatratio>
                        translate <0,rCover,zBinding>
                        texture{T_Binding translate -x*xBook*0.5}
                } 
                
        }
        // -------------------------------------------
        // pages        
        // -------------------------------------------

        union{
                difference{
                        box{0,<xPage,yPage,zPage>}
                        cylinder{-y*0.1,y*yPage*1.1,xPage*0.5 scale <1,1,flatratio*rand(rd)> translate <xPage*0.5,0,zPage>}
                }
                difference{
                        cylinder{0,y*yPage,xPage*0.5}
                        cylinder{-y*0.1,y*yPage*1.1,xPage*0.5 scale <1,1,0.5> translate -z*0.5*xPage}
                        scale <1,1,flatratio> translate x*xPage*0.5
                }                                                            
                
                translate <-xPage*0.5,2*eCover,zBinding>
                texture{T_Page}
        } 
        
        translate x*xBook*0.5
        texture{T_Cover}
}
#end  

// -----------------------------------------
// end of mBook macro
// =========================================

// =========================================
// mRandomText macro 1.0
// -----------------------------------------
// Copyright Gilles Tran 1999
// -----------------------------------------
// This macro creates a random text of nLetters letters
// -----------------------------------------
// local the font path and names before using this file.
// For example :
// #local fontpath="\windows\fonts\\"
// #local fontname_1="arial.ttf"
// #local fontname_2="times.ttf"
// -----------------------------------------
#macro mRandomText(nLetters)
        #local rtext=""
        #if (rand(rd)<0.5)
                #local fontname=concat(fontpath,fontname_1)
        #else
                #local fontname=concat(fontpath,fontname_2)
        #end                
//                #warning fontname
        #local i=0;
        #if (rand(rd)<0.5)
                #local asciistart=65; // majuscule
        #else
                #local asciistart=97; // minuscule
        #end
        #while (i<nLetters)
                #local rtext=concat(rtext,chr(asciistart+int(27*rand(rd))))
                #local i=i+1;                  
        #end
        text{ttf fontname rtext 1,0}
#end
// -----------------------------------------
// end of mRandomText macro
// =========================================
// =========================================
// mpatBinder macro 1.0
// -----------------------------------------
// This macro defines several patterns for an old book binder
// it returns the pattern typePattern
// C_Dom is the dominant color
// C_Trim_1 is a secondary color
// C_Trim_2 is a third color, usually gold             
// 
// the macro returns a pigment color starting on <0,0,0> going to <1,1,1>
#macro mpatBinder(typePattern,C_Dom,C_Trim_1,C_Trim_2)
#local yvar=rand(rd)*0.25; // this variable is used to "slide" the pattern vertically so that the stripes change place
pigment{
        #switch (typePattern)
        #case (0) // dom/gold/black/gold/trim/gold/dom
                gradient y
                #declare p1=pigment{
                        gradient y
                        color_map{
                                [0 color C_Dom*0.8]
                                [0.1 color C_Dom]
                                [0.5+yvar color C_Dom]
                                [0.5+yvar color C_Trim_2]
                                [0.52+yvar color C_Trim_2]
                                [0.52+yvar color C_Dom*0.01]
                                [0.6+yvar color C_Dom*0.01]
                                [0.6+yvar color C_Trim_2]
                                [0.62+yvar color C_Trim_2]
                                [0.62+yvar color C_Trim_1]
                                [0.75+yvar color C_Trim_1]
                                [0.75+yvar color C_Trim_2]
                                [0.77+yvar color C_Trim_2]
                                [0.77+yvar color C_Dom]
                                [1 color C_Dom*0.8]
                        }
                }
                #declare p2=pigment{
                                spherical
                                translate y*0.5
                                color_map{
                                        [0 C_Dom*0.01]
                                        [0.7+yvar C_Dom*0.01]
                                        [0.7+yvar C_Trim_2]
                                        [1 C_Trim_2]
                                }
                        scale 0.08
                        translate x*0.5 
                        translate y*(0.52+yvar)
                }                          
                pigment_map{
                        [0 p1]
                        [0.52+yvar p1]
                        [0.52+yvar p2]
                        [0.6+yvar p2]
                        [0.6+yvar p1]
                        [1 p1]
                }
        #break        
        
        #case (1) // dom/gold/black/gold/trim boxed
                boxed          
                translate y
                warp{repeat y*2} 
                scale <0.5,2/((int(rand(rd)*5)+1)*4),1>
                translate x*0.5 
                color_map{
                        [0 C_Dom]
                        [0.3+yvar C_Dom]
                        [0.3+yvar C_Trim_2]
                        [0.35+yvar C_Trim_2]
                        [0.35+yvar C_Dom*0.01]
                        [0.4+yvar C_Dom*0.01]
                        [0.4+yvar C_Trim_2]
                        [0.45+yvar C_Trim_2]
                        [0.45+yvar C_Trim_1]
                        [1 C_Trim_1]
                }
        #break        
        
        #case (2) // dom/gold/dom/gold/dom/gold/black/gold/dom/gold/dom
                gradient y
                #declare p1=pigment{
                        gradient y
                        color_map{
                                [0 color C_Dom*0.8]
                                [0.05+yvar color C_Dom]
                                [0.05+yvar color C_Trim_2]
                                [0.06+yvar color C_Trim_2]
                                [0.06+yvar color C_Dom]
                                [0.22+yvar color C_Dom]
                                [0.22+yvar color C_Trim_2]
                                [0.23+yvar color C_Trim_2]
                                [0.23+yvar color C_Dom]
                                [0.50+yvar color C_Dom]
                                [0.50+yvar color C_Trim_2]
                                [0.51+yvar color C_Trim_2]
                                [0.51+yvar color C_Dom*0.01]
                                [0.72+yvar color C_Dom*0.01]
                                [0.72+yvar color C_Trim_2]
                                [0.73+yvar color C_Trim_2]
                                [0.73+yvar color C_Dom]
                                [0.84+yvar color C_Dom]
                                [0.84+yvar color C_Trim_2]
                                [0.85+yvar color C_Trim_2]
                                [0.85+yvar color C_Dom]
                                [1 color C_Dom*0.8]
                        }
                }
                #declare p2=pigment{
                                spherical
                                translate x
                                warp{repeat x*2}
                                color_map{
                                        [0 C_Dom*0.01]
                                        [0.7+yvar C_Dom*0.01]
                                        [0.7+yvar C_Trim_2]
                                        [1 C_Trim_2]
                                }
                        scale 0.5
                        scale 0.21
                        translate x*0.5 
                        translate y*(0.51+yvar+0.21/2)
                }                          
                pigment_map{
                        [0 p1]
                        [0.51+yvar p1]
                        [0.51+yvar p2]
                        [0.72+yvar p2]
                        [0.72+yvar p1]
                        [1 p1]
                }
        #break        
        #case (3) // dom/gold/ dom /gold /dom  rims
                gradient y
                #declare p1=pigment{
                        gradient y
                        scale 0.1+yvar
                        color_map{
                                [0 C_Dom*0.7]
                                [1 C_Dom]
                        }
                }
                #declare p2=pigment{C_Trim_2}
                #declare p3=pigment{
                        gradient y
                        triangle_wave
                        scale rand(rd)*0.5
                        color_map{
                                [0 C_Dom*0.4]
                                [0.4 C_Dom]
                                [1 C_Dom*1.3]
                        }
                }

                pigment_map{
                        [0.00 p1]
                        [yvar p1]
                        [yvar p2]
                        [0.02+yvar p2]
                        [0.02+yvar p3]
                        [1-yvar-0.02 p3]
                        [1-yvar-0.02 p2]
                        [1-yvar p2]
                        [1-yvar p1 scale -1 translate y]
                        [1.00 p1 scale -1 translate y]
                }
        #break        
        #case (4) // dom/gold/ rims /gold /dom losange
                gradient y
                #declare p1=pigment{
                        gradient y
                        color_map{
                                [0 C_Dom*0.7]
                                [0.7 C_Dom]
                                [0.7 C_Trim_2]
                                [1 C_Trim_2]
                        }
                        scale 0.1
                }
                #declare p3=pigment{
                        gradient y
                        color_map{
                                [0 C_Trim_2]
                                [0.1 C_Trim_2]
                                [0.1 C_Dom]
                                [1 C_Dom*0.3]
                        }
                        scale 0.2
                        translate y*0.8
                }
                #declare p2=pigment{
                                boxed           
                                rotate z*45
                                translate y
                                warp{repeat y*2} 
                                scale <0.5,2/((int(rand(rd)*5)+1)*4),1>
//                                scale <0.5,2/8,1>
                                translate x*0.5 
                                color_map{
                                        [0 C_Dom]
                                        [0.4+yvar C_Dom]
                                        [0.4+yvar C_Trim_2]
                                        [0.45+yvar C_Trim_2]
                                        [0.45+yvar C_Dom*0.01]
                                        [0.5+yvar C_Dom*0.01]
                                        [0.5+yvar C_Trim_2]
                                        [0.65+yvar C_Trim_2]
                                        [0.65+yvar C_Trim_1]
                                        [1 C_Trim_1]
                                }
                        scale <1,0.7,1>
                        translate y*0.1
                }
                pigment_map{
                        [0 p1]
                        [0.1 p1]
                        [0.1 p2]
                        [0.8 p2]
                        [0.8 p3]
                        [1 p3]
                }

        #break

        #case (5) // black/gold/speckled dom/gold/black
                gradient y
                #declare p1=pigment{C_Dom*0.001}
                #declare p2=pigment{C_Trim_2}
                #declare p3=pigment{
                        bozo
                        translate yvar*10
                        color_map{
                                [0 C_Dom]
                                [0.7 C_Dom]
                                [0.7 C_Dom*0.3]
                                [1 C_Dom*0.3]
                        }
                        scale rand(rd)*0.05
                }
                pigment_map{
                        [0.00 p1]
                        [yvar p1]
                        [yvar p2]
                        [0.02+yvar p2]
                        [0.02+yvar p3]
                        [1-yvar-0.08 p3]
                        [1-yvar-0.08 p2]
                        [1-yvar-0.06 p2]
                        [1-yvar-0.06 p1]
                        [1-yvar-0.04 p1]
                        [1-yvar-0.03 p2]
                        [1-yvar p2]
                        [1-yvar p1 scale -1 translate y]
                        [1.00 p1 scale -1 translate y]
                }
        #break
        #case (6) // black/gold/agate dom/gold/black
                gradient y
                #declare p0=pigment{C_Dom*0.001}
                #declare p1=pigment{C_Dom}
                #declare p2=pigment{C_Trim_2}
                #declare p3=pigment{
                        agate
                        translate yvar*10
                        color_map{
                                [0 C_Trim_1]
                                [0.7 C_Trim_1]
                                [0.7 C_Trim_1*0.3]
                                [1 C_Trim_1*0.3]
                        }
                        scale rand(rd)*0.1
                }
                pigment_map{
                        [0.00 p3]
                        [yvar p3]
                        [yvar p2]
                        [0.02+yvar p2]
                        [0.02+yvar p1]
                        [1-yvar-0.08 p1]
                        [1-yvar-0.08 p2]
                        [1-yvar-0.06 p2]
                        [1-yvar-0.06 p0]
                        [1-yvar-0.02 p0]
                        [1-yvar-0.02 p2]
                        [1-yvar p2]
                        [1-yvar p3 scale -1 translate y]
                        [1.00 p3 scale -1 translate y]
                }
        #break
        #case (7) 
                gradient y
                #declare p0=pigment{C_Dom*0.001}
                #declare p1=pigment{C_Dom}
                #declare p2=pigment{C_Trim_2}
                #declare p3=pigment{
                        crackle
                        translate yvar*10
                        color_map{
                                [0 C_Trim_2]
                                [0.025 C_Trim_2]
                                [0.025 C_Dom*0.3]
                                [1 C_Dom*0.3]
                        }
                        scale <0.1,0.03,0.1>*4
                }
                pigment_map{
                        [0.00 p0]
                        [yvar*0.1 p0]
                        [yvar*0.1 p2]
                        [yvar*0.1+0.01 p2]
                        [yvar*0.1+0.01 p3]
                        [1-yvar-0.08 p3]
                        [1-yvar-0.08 p2]
                        [1-yvar-0.06 p2]
                        [1-yvar-0.06 p0]
                        [1-yvar-0.02 p0]
                        [1-yvar-0.02 p2]
                        [1-yvar p2]
                        [1-yvar p0 scale -1 translate y]
                        [1.00 p0 scale -1 translate y]
                }
        #break
        #case (8) 
                gradient y   
                turbulence 0.01
                scale <yvar,1,1>
//                #declare C_Dom=rgb<0.7+yvar,0.7+yvar*0.5,0.7>;
                #declare p0=pigment{
                        gradient x 
                        turbulence 1                     
                        triangle_wave
                        color_map{
                                [0 C_Dom*1.5]
                                [1 C_Dom*0.3*1.5]
                        }
                }
                #declare p1=pigment{
                        gradient x 
                        turbulence 1                     
                        triangle_wave
                        color_map{
                                [0 C_Dom*0.5]
                                [1 C_Dom*0.3*0.5]
                        }
                }
                #declare p2=pigment{
                        gradient x                      
                        turbulence 1
                        triangle_wave
                        color_map{
                                [0 C_Dom]
                                [1 C_Dom*0.3]
                        }
                }
                pigment_map{
                        [0.00 p0]
                        [0.02 p1]
                        [0.5 p2]
                        [1.00-yvar-0.1 p2]
                        [1.00-yvar-0.1 p0]
                        [1.00-yvar-0.01 p0]
                        [1.00-yvar p1]
                        [0.99 p1]
                        [1.00 p0]
                }
        #break
        #case (9) 
                gradient y   
                turbulence 0.01
                #declare p0=pigment{
                        gradient x 
                        turbulence 1                     
                        triangle_wave
                        color_map{
                                [0 C_Dom*1.5]
                                [1 C_Dom*0.3*1.5]
                        }
                }
                #declare p1=pigment{
                        gradient x 
                        turbulence 1                     
                        scale <yvar,1,1>
                        triangle_wave
                        color_map{
                                [0 C_Dom*0.5]
                                [1 C_Dom*0.3*0.5]
                        }
                }
                #declare p2=pigment{
                        gradient x                      
                        turbulence 1
                        scale <yvar,1,1>
                        triangle_wave
                        color_map{
                                [0 C_Dom]
                                [1 C_Dom*0.3]
                        }
                }
                #declare p3=pigment{
                        spherical
                        color_map{
                                [0 C_Dom*0.3]
                                [0.6 C_Dom*0.3]
                                [0.6 C_Trim_2]
                                [1 C_Trim_2]
                        }        
                        translate y*0.5
                        scale 0.3*<1,0.3,1>
                        translate y*(0.02+yvar*0.5)
                        translate x*0.5
                }
                pigment_map{
                        [0.00 p0]
                        [0.02 p1]
                        [0.02+yvar*0.5 p1]
                        [0.02+yvar*0.5 p3]
                        [0.22+yvar*0.5 p3]
                        [0.22+yvar*0.5 p2]
                        [0.99 p1]
                        [1.00 p0]
                }
        #break
        #else
                gradient y   
                turbulence 0.01
                #declare p0=pigment{
                        agate
                        translate yvar*10
                        color_map{
                                [0 C_Dom*1.5]
                                [1 C_Dom*0.3*1.5]
                        }
                }
                #declare p1=pigment{
                        agate
                        triangle_wave
                        translate yvar*10
                        color_map{
                                [0 C_Dom*0.5]
                                [1 C_Dom*0.3*0.5]
                        }
                }
                #declare p2=pigment{
                        agate
                        translate yvar*10
                        triangle_wave
                        color_map{
                                [0 C_Dom]
                                [1 C_Dom*0.3]
                        }
                }
                #declare p3=pigment{
                        gradient x
                        turbulence 0.3
                        triangle_wave
                        scale <yvar,1,1>
                        color_map{
                                [0 C_Dom*0.3]
                                [0.6 C_Dom*0.3]
                                [0.6 C_Trim_2]
                                [1 C_Trim_2]
                        }        
                }
                pigment_map{
                        [0.00 p0]
                        [0.02 p1]
                        [0.02+yvar*0.2 p1]
                        [0.02+yvar*0.2 p3]
                        [0.22+yvar*0.2 p3]
                        [0.22+yvar*0.2 p2]
                        [0.99 p1]
                        [1.00 p0]
                }
        #end
}              
#end
// -----------------------------------------
// end of mpatBinder macro
// =========================================
