//=========================================
// Window generator macro
// -----------------------------------------
// Made for Persistence of vision 3.6
//==========================================  
// Copyright 2000-2004 Gilles Tran http://www.oyonale.com
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
// Windows type 3 added by Jerôme Berger
//=========================================
// This file contains 4 macros to build windows
// mWindow: window panes and wood frame
// mWindowCase : window stone casing
// mBalcony : balcony    
// mShutter : creates shutters
//=========================================
// mWindow macro
//-----------------------------------------
// It creates an openable window
// The window can rotate arount the y axis (type 1 and 2)
// or the panes can slide on each other (type 3 and 4)
// The window is on the x-y plane and opens toward -z
//-----------------------------------------
// Type 1 and 2 The panes rotate around their hinges
//  !-------------------! yF
//  ! !--!!--! !------! !
//  ! !  !!  ! !  !!  ! !
//  ! !__!!__! !__!!__! !
//  ! !--!!--! !--!!--! !
//  ! !  !!  ! !  !!  ! !
//  ! !__!!__! !__!!__! !
//  ! !--!!--! !--!!--! !
//  ! !  !!  ! !  !!  ! !
//  ! !  !!  ! !  !!  ! !
//  ! !--!!--! !------! !
//  !-------------------!
//  -xF       0         xF
//  Window with 2 panes (typeF=2), 1 vertical bar (nFx=1) and 2 horizontal bars (nFy=2)
//-----------------------------------------
// Type 3 The bottom pane slides upward over the top pane
//  !-------------------! yF
//  ! !---------------! !
//  ! !               ! !
//  ! !      /\       ! !
//  ! !      !!       ! !
//  !-------------------!
//  ! ----------------- !
//  ! !               ! !
//  ! !               ! !
//  ! !               ! !
//  ! !---------------! !
//  !-------------------!
//  -xF       0         xF
//  
//-----------------------------------------
// Type 4 The left pane slides over the top pane
//  !----------!--------! yF
//  ! !------! !------! !
//  ! !      ! !      ! !
//  ! !      ! !      ! !
//  ! !      ! !      ! !
//  ! !      ! ! =>   ! !
//  ! !      ! !      ! !
//  ! !      ! !      ! !
//  ! !      ! !      ! !
//  ! !      ! !      ! !
//  ! !------! !------! !
//  !----------!--------!
//  -xF       0         xF
//  
/*
#declare typeF=2;       // window type : 1= 1 pane ; 2= 2 panes ; 3 = horizontal sliding ; 4 = vertical sliding
#declare xF1=3;         // Width of the half-window (pane width if 2 panes) -xF to xF
#declare yF=9;          // Height of window
#declare zF=0.33;       // Thickness of window
#declare eF1=0.2;       // Thickness of wood frame
#declare eF2=0.05;      // Thickness of wood frame (inner 1)
#declare eF3=0.05;      // Thickness of wood frame (inner 2)
#declare nFx=1;         // Number of vertical bars (pane separators)
#declare nFy=2;         // Number of horizontal bars (pane separators)
#declare tetaFG=40;     // type 1 & 2 : angle (degrees) of left pane (0=closed pane)
                        // type 3 : percentage of opening (0=closed pane 100=open pane) of the bottom pane
                        // type 4 : percentage of opening (0=closed pane 100=open pane) of the left pane
#declare tetaFD=0;      // angle of right pane
#declare yHinge=0.4;     // height of half hinge
#declare rHinge=0.07;    // hinge radius
#declare T_F1=texture{pigment{Green}} // wood frame texture
#declare T_F2=texture{pigment{White}} // inner wood frame & bars texture 
#declare T_V=texture{pigment{rgbt<0.9,0.8,0.2,0.2>}} // glass texture
*/
//-----------------------------------------
//-----------------------------------------
// Type 1 = one pane
//-----------------------------------------
// closed
//#declare Window_1_c=object{mWindow(1,xL,yL,0.2,0.3,0.1,0.1,0,2,0,0,0.5,0.1,T_Window1,T_Window2,T_Glass1)}
// part open
//#declare Window_1_o=object{mWindow(1,xL,yL,0.2,0.3,0.1,0.1,0,2,-120,-110,0.5,0.1,T_Window1,T_Window2,T_Glass1)}
//-----------------------------------------
// Type 2 = two panes
//-----------------------------------------
// closed, 0 vertical bars, 2 horizontal bars
//#declare Window_2_c1=object{mWindow(2,xL,yL,0.2,0.3,0.1,0.1,0,2,0,0,0.5,0.1,T_Window1,T_Window2,T_Glass1)}
// part open, 0 vertical bars, 2 horizontal bars
//#declare Window_2_o1=object{mWindow(2,xL,yL,0.2,0.3,0.1,0.1,0,2,-120,-110,0.5,0.1,T_Window1,T_Window2,T_Glass1)}
// closed, 1 vertical bars, 3 horizontal bars
//#declare Window_2_c2=object{mWindow(2,xL,yL,0.2,0.3,0.1,0.1,1,3,0,0,0.5,0.1,T_Window1,T_Window2,T_Glass1)}
// part open, 1 vertical bars, 3 horizontal bars
//#declare Window_2_o2=object{mWindow(2,xL,yL,0.2,0.3,0.1,0.1,1,3,-130,-150,0.5,0.1,T_Window1,T_Window2,T_Glass1)}
//-----------------------------------------
// Type 3 = vertical sliding
//-----------------------------------------
// closed
//#declare Window_3_c=object{mWindow(3,xL,yL,0.2,0.3,0.1,0.1,0,0,0,0,0.5,0.1,T_Window1,T_Window2,T_Glass1)}
// part open (60%)
//#declare Window_3_o1=object{mWindow(3,xL,yL,0.2,0.3,0.1,0.1,0,0,60,0,0.5,0.1,T_Window1,T_Window2,T_Glass1)}
// fully open
//#declare Window_3_o2=object{mWindow(3,xL,yL,0.2,0.3,0.1,0.1,0,0,100,0,0.5,0.1,T_Window1,T_Window2,T_Glass1)}

//-----------------------------------------
// Type 4 = horizontal sliding
//-----------------------------------------
// closed
//#declare Window_4_c=object{mWindow(4,xL,yL,0.2,0.3,0.1,0.1,0,0,0,0,0.5,0.1,T_Window1,T_Window2,T_Glass1)}
// part open (60%)
//#declare Window_4_o1=object{mWindow(4,xL,yL,0.2,0.3,0.1,0.1,0,0,60,0,0.5,0.1,T_Window1,T_Window2,T_Glass1)}
// fully open
//#declare Window_4_o2=object{mWindow(4,xL,yL,0.2,0.3,0.1,0.1,0,0,100,0,0.5,0.1,T_Window1,T_Window2,T_Glass1)}

#macro mWindow(typeF,xF1,yF1,zF,eF1,eF2,eF3,nFx,nFy,tetaFG,tetaFD,yHinge,rHinge,T_F1,T_F2,T_V)
#switch (typeF)
        #case (1) // one pane
                #local xF=xF1*2;
                #local yF=yF1;
        #break
        #case (2) // two panes
                #local xF=xF1;
                #local yF=yF1;
        #break
        #case (3) // vertical sliding
                #local xF=xF1*2;
                #local yF=(yF1+eF1)/2; // the panes overlap
        #break
        #case (4) // horizontal sliding
                #local xF=xF1+eF1/2; // the panes overlap
                #local yF=yF1;
        #break
#end

//-----------------------------------------
// Hinge
//-----------------------------------------
#local Hinges=union{
        union{
                union{cylinder{0,y*yHinge,rHinge} sphere{y*yHinge,rHinge} translate y*rHinge*0.2}
                union{cylinder{0,-y*yHinge,rHinge} sphere{-y*yHinge,rHinge} translate -y*rHinge*0.2}
                translate y*yF/4
        }
        union{
                union{cylinder{0,y*yHinge,rHinge} sphere{y*yHinge,rHinge} translate y*rHinge*0.2}
                union{cylinder{0,-y*yHinge,rHinge} sphere{-y*yHinge,rHinge} translate -y*rHinge*0.2}
                translate y*3*yF/4
        }
}           
//-----------------------------------------
// Creates the window pane
//-----------------------------------------
#local Pane=union{
        // Glass
                union{
                        triangle{<0,0,0>,<xF,0,0>,<xF,yF,0>}
                        triangle{<0,0,0>,<0,yF,0>,<xF,yF,0>}
                        translate z*eF2*2
                        texture{T_V}
                }      
        // Frame
                difference{
                        box{<0,0,0>,<xF,yF,zF>}
                        box{<eF1,eF1,-1>,<xF-eF1,yF-eF1,zF*3>}
                }              
                difference{
                        box{<eF1,eF1,eF2>,<xF-eF1,yF-eF1,zF>}
                        box{<eF1+eF2,eF1+eF2,-1>,<xF-eF1-eF2,yF-eF1-eF2,zF*3>}
                        texture{T_F2}
                }       
        // Vertical bars
                #if (nFx>0)
                        #local Count=0;    
                        #local imF=(xF-2*(eF1+eF2))/(nFx+1);
                        #while (Count<nFx)
                                box{<0,eF2+eF1,0>,<eF3,yF-eF2-eF1,eF3>
                                translate <-eF3*0.5,0,-eF3*0.5>
                                rotate y*45
                                scale <2,1,1>
                                translate z*eF2*1.414
                                translate x*((Count+1)*imF+eF1+eF2)
                                texture{T_F2}
                                }
                        #local Count=Count+1;
                        #end
                #end
        // Horizontal bars
                #if (nFy>0)
                        #local Count=0;
                        #local imF=(yF-2*(eF1+eF2))/(nFy+1);
                        #while (Count<nFy)
                                box{<eF1+eF2,0,0>,<xF-eF1-eF2,eF3,eF3>
                                translate <0,-eF3*0.5,-eF3*0.5>
                                rotate x*45
                                scale <1,2,1>
                                translate z*eF2*1.414
                                translate y*((Count+1)*imF+eF1+eF2)
                                texture{T_F2}
                                }
                        #local Count=Count+1;
                        #end       
                #end
}        
//-----------------------------------------
// puts the window together
//-----------------------------------------
union{
        #switch (typeF)
                #case (1)
                        object{Pane}
                        object{Hinges translate <-rHinge,0,0>}
                        translate rHinge*x
                        rotate -y*tetaFG
                        translate -rHinge*x
                        translate -x*xF1
                #break
                #case (2)
                union{
                        object{Pane}
                        object{Hinges translate <-rHinge,0,0>}
                        translate rHinge*x
                        rotate -y*tetaFG
                        translate -rHinge*x
                        translate -x*xF
                }
                union{
                        object{Pane}            
                        box{<xF-eF1+eF2,0,-eF2>,<xF+eF1-eF2,yF,0>}
                        cylinder{0,y*yF,(eF1-eF2)*0.8 scale <1,1,0.5> translate x*xF}
                        object{Hinges translate <-rHinge,0,0>}
                        translate rHinge*x
                        rotate -y*tetaFD
                        translate -rHinge*x
                        translate -x*xF
                        scale <-1,1,1>
                }  
                #break

                #case(3)
                        object {Pane translate -zF*1.001*z +(tetaFG/100)*(yF1-eF1)/2*y -x*xF1} // front bottom pane, slides
                        object {Pane translate (yF1-eF1)/2*y -x*xF1} // back top pane, doesn't slide
                #break

                #case(4)
//                        box{0,<xF,0.2,0.1> translate y*yF/2 -x*xF1 -z*zF*3 pigment{Red}}
//                        box{0,<xF,0.2,0.1> translate y*(yF/2+0.2) -x*eF1/2 -z*zF*3 pigment{Red}}
                        object {Pane translate -zF*1.001*z +(tetaFG/100)*(xF1-eF1/2)*x - x*xF1} // front left pane, slides
                        object {Pane translate -x*eF1/2} // back right pane, doesn't slide
                #break
        #end
texture{T_F1}
}
#end

//=========================================
// mBalcony macro
//-----------------------------------------
// It creates an balcony for the window
// 6 types available
// Type 1 = horizontal bars
// Type 2 = old style
// Type 3 = crossed bars XXXXXX
// Type 4 = stone ornaments 1
// Type 5 = stone ornaments 2
// Type 6 = vertical bars
//-----------------------------------------
/*
#declare typeB=1;       // Balcony type       
#declare xB=3;          // Half-width (-xB to xB) 
#declare yB=4;          // Height
#declare zB=1;          // Ledge depth
                        // if 0 then the balcony is inside the window
                        // if > 0 then sides are created
#declare eB=0.1;        // Bar radius
#declare eB2=0.5;       // Other radius (ornament radius in type 4 & 5)
#declare eB3=1;         // width of lateral bars in type 1 with ledge
#declare nB=1;          // Number of bars or ornaments
#declare T_Balcon=texture{pigment{White}} // Texture
*/
// ==================================================================
// 2 x 6 balconies types (with or without ledge)
//-----------------------------------------
// Type 1 = horizontal bars
//-----------------------------------------
//#declare Balcony_1_wl=object{mBalcony(1,xL  ,4,1  ,0.1,0.5,0.5,3,T_Balcon1)} //(with ledge)
//#declare Balcony_1_nl=object{mBalcony(1,3  ,4,0  ,0.1,0.5,0.5,3,T_Balcon1)} //(no ledge)
//-----------------------------------------
// Type 2 = old style
//-----------------------------------------
//#declare Balcony_2_wl=object{mBalcony(2,3.3,4,1.3,0.1,0.5,0  ,5,T_Balcon1)} //(with ledge)
//#declare Balcony_2_nl=object{mBalcony(2,3.3,4,0  ,0.1,0.5,0  ,5,T_Balcon1)} //(no ledge)
//-----------------------------------------
// Type 3 = crossed bars XXXXXX
//-----------------------------------------
//#declare Balcony_3_wl=object{mBalcony(3,3.7,4,1.3,0.1,0.5,0  ,5,T_Balcon1)} //(with ledge)
//#declare Balcony_3_nl=object{mBalcony(3,3.5,4,0  ,0.1,0.5,0  ,5,T_Balcon1)} //(with ledge)
//-----------------------------------------
// Type 4 = stone ornaments 1
//-----------------------------------------
//#declare Balcony_4_wl=object{mBalcony(4,3.5,4,4  ,0.3,0.2,0  ,5,T_Balcon2)} //(with ledge)
//#declare Balcony_4_nl=object{mBalcony(4,3.5,4,0  ,0.3,0.2,0  ,5,T_Balcon2)} //(no ledge)
//-----------------------------------------
// Type 5 = stone ornaments 2
//-----------------------------------------
//#declare Balcony_5_wl=object{mBalcony(5,3.5,4,4  ,0.3,0.2,0  ,5,T_Balcon2)} //(width ledge)
//#declare Balcony_5_nl=object{mBalcony(5,3.5,4,0  ,0.3,0.2,0  ,5,T_Balcon2)} //(no ledge)
//-----------------------------------------
// Type 6 = vertical bars
//-----------------------------------------
//#declare Balcony_6_wl=object{mBalcony(6,3.5,4,4  ,0.1,0.2,0  ,5,T_Balcon1)} //(width ledge)
//#declare Balcony_6_nl=object{mBalcony(6,3.5,4,0  ,0.1,0.2,0  ,5,T_Balcon1)} //(no ledge)
//-----------------------------------------

#macro mBalcony(typeB,xB,yB,zB,eB,eB2,eB3,nB,T_Balcon)
union{
#switch (typeB)                                  
        // horizontal bars
        #case (1)                
                #local Count=0;             
                #local iB=(yB-eB2)/(nB-1);
                #while (Count<nB)
                        cylinder{-x*xB,x*xB,eB translate y*(eB2+Count*iB)}
                        #if (zB>0)
                                union{
                                        cylinder{-x*(eB3+xB)+z*zB,-x*xB,eB}
                                        sphere{-x*xB,eB}
                                        cylinder{x*(eB3+xB)+z*zB,x*xB,eB}
                                        sphere{x*xB,eB}
                                        translate y*(eB2+Count*iB)
                                }
                        #end
                        #local Count=Count+1;
                #end
                translate -z*zB
        #break
        // old style
        #case (2)                               
                        cylinder{-x*xB,x*xB,eB translate y*yB}
                        cylinder{-x*(xB-eB2),x*(xB-eB2),eB translate y*(yB-eB2)}
                        cylinder{-x*(xB-eB2),x*(xB-eB2),eB translate y*eB2}
                        cylinder{0,y*yB,eB translate -x*xB}
                        cylinder{0,y*yB,eB translate x*xB}
                        cylinder{y*eB2,y*(yB-eB2),eB translate -x*(xB-eB2)}
                        cylinder{y*eB2,y*(yB-eB2),eB translate x*(xB-eB2)}
                        cylinder{<-xB,yB,0>,<-xB+eB2,yB-eB2,0>,eB}
                        cylinder{<xB,yB,0>,<xB-eB2,yB-eB2,0>,eB}
                        cylinder{<-xB,0,0>,<-xB+eB2,eB2,0>,eB}
                        cylinder{<xB,0,0>,<xB-eB2,eB2,0>,eB}
                        #local iB=(xB-eB2)*2/(nB+1);
                        torus{(iB-eB2*0.5)*0.5,eB rotate x*90 scale <1,0.8*(iB-eB2)/(iB-eB2*0.5),1> translate <-xB+eB2+(iB-eB2*0.5)*0.5,yB*0.5,0>}
                        torus{(iB-eB2*0.5)*0.5,eB rotate x*90 scale <1,0.8*(iB-eB2)/(iB-eB2*0.5),1> translate <xB-(eB2+(iB-eB2*0.5)*0.5),yB*0.5,0>}
                        #local Count=0;
                        #while (Count<nB)                      
                                union{  
                                        intersection{torus{eB2*0.5,eB rotate x*90} plane{y,0 inverse} translate y*(yB-1.5*eB2-2*eB)}
                                        intersection{torus{eB2*0.5,eB rotate x*90} plane{y,0} translate y*(1.5*eB2+2*eB)}
                                        cylinder{y*(1.5*eB2+2*eB),y*(yB-(1.5*eB2+2*eB)),eB translate -x*eB2*0.5}
                                        cylinder{y*(1.5*eB2+2*eB),y*(yB-(1.5*eB2+2*eB)),eB translate x*eB2*0.5}
                                        #if (Count<nB-1)          
                                                #if (iB>eB2)
                                                        torus{(iB-eB2)*0.5,eB rotate x*90 translate <iB*0.5,yB*0.5,0>}
                                                        torus{eB2*0.5,eB rotate x*90 translate <iB*0.5,yB-eB2*0.5,0>}
                                                        torus{eB2*0.5,eB rotate x*90 translate <iB*0.5,eB2*0.5,0>}
                                                #end
                                        #end
                                        translate x*((Count+1)*iB-xB+eB2)
                                }
                        #local Count=Count+1;
                        #end
                        #if (zB>0)
                                cylinder{x*(eB3+xB)+z*zB,x*xB,eB}
                                cylinder{-x*(eB3+xB)+z*zB,-x*xB,eB}
                                cylinder{x*(eB3+xB)+z*zB,x*xB,eB translate y*yB}
                                cylinder{-x*(eB3+xB)+z*zB,-x*xB,eB translate y*yB}
                                cylinder{x*(eB3+xB)+z*zB,x*xB,eB translate y*yB*0.5}
                                cylinder{-x*(eB3+xB)+z*zB,-x*xB,eB translate y*yB*0.5}
                        #end
                        
                        translate -z*zB                                                                                 
                                                                                 
        #break
        // crossed bars XXXXXX
        #case (3)                                         
                cylinder{-x*xB,x*xB,eB translate y*yB}
                cylinder{-x*xB,x*xB,eB translate y*eB2}
                cylinder{0,y*yB,eB translate -x*xB}
                #local iB=xB*2/(nB+1);
                #local Count=0;
                #while (Count<=nB)                      
                        union{                      
                                cylinder{<-iB,eB2,0>,<0,yB,0>,eB}
                                cylinder{<-iB,yB,0>,<0,eB2,0>,eB}
                                #if (Count=nB)
                                        cylinder{<0,0,0>,<0,yB,0>,eB}
                                #else
                                        cylinder{<0,eB2,0>,<0,yB,0>,eB}
                                #end
                                sphere{0,eB*2 translate <-iB*0.5,(yB-eB2)*0.5+eB2,0>}
                                translate x*(iB*(Count+1)-xB)
                        }
                        #local Count=Count+1;
                #end
                #if (zB>0)
                        cylinder{x*(eB3+xB)+z*zB,x*xB,eB translate y*eB2}
                        cylinder{-x*(eB3+xB)+z*zB,-x*xB,eB translate y*eB2}
                        cylinder{x*(eB3+xB)+z*zB,x*xB,eB translate y*yB}
                        cylinder{-x*(eB3+xB)+z*zB,-x*xB,eB translate y*yB}
                        cylinder{x*(eB3+xB)+z*zB,x*xB,eB translate y*((yB-eB2)*0.5+eB2)}
                        cylinder{-x*(eB3+xB)+z*zB,-x*xB,eB translate y*((yB-eB2)*0.5+eB2)}
                #end
                translate -z*zB                                                                                 
                
                
        #break
        // ornaments 1
        #case (4)                                          
                #local PotBalcon=
                        lathe{cubic_spline 10,
                        <1, -3>, <1, 0>, <1.1, 1>,<2, 1.8>, <2.2, 2.2>,
                        <2,3.1>,<1.2,4>,<1,6>,<1.5,7>,<1.5,8>
                        scale <eB2,(yB-2*eB)/7,eB2>
                        }
                union{
                        box{<-xB-eB,0,-eB*2>,<xB+eB,eB,eB>}        
                        box{<-xB,-eB*2,-eB>,<xB,0,eB>}        
                        translate y*yB
                }                    
                #local iB=(xB-eB)*2/(nB-1);
                #local Count=0;
                #while (Count<nB)
                        object{PotBalcon
                        translate x*(-xB+eB+(Count*iB))
                        }
                #local Count=Count+1;
                #end
                                                  
                #if (zB>0)
                        union{
                                box{<-xB-eB,0,-eB*2>,<-xB+eB,eB,zB>}
                                box{<-xB,-eB*2,-eB>,<-xB+eB,0,zB>}
                                box{<xB-eB,0,-eB*2>,<xB+eB,eB,zB>}
                                box{<xB-eB,-eB*2,-eB>,<xB,0,zB>}
                                translate y*yB
                        }                                                        
                        #local Count=1;
                        #while (Count*iB<zB)                      
                                object{PotBalcon translate <xB-eB,0,iB*Count>}
                                object{PotBalcon translate <-xB+eB,0,iB*Count>}
                                #local Count=Count+1;
                        #end
                #end
                translate -z*zB                                                                                 
                
        #break
        // ornaments 2
        #case (5)                                          
                #local PotBalcon=
                        lathe{cubic_spline 11,
                        <2, -3>, <1, 0>, <1.5, 2>,<2.5, 3>, <2.1, 3.5>,
                        <1.32,4.1>,<1.5,3.7>,<2.1,6>,<2.5,7>,<1.5,8>,<1,9>
                        translate y*-8
                        scale <1,-1,1>
                        scale <eB2,(yB-2*eB)/8,eB2>
                        }
                union{
                        box{<-xB-eB,0,-eB*2>,<xB+eB,eB,eB>}        
                        box{<-xB,-eB*2,-eB>,<xB,0,eB>}        
                        translate y*yB
                }                    
                #local iB=(xB-eB)*2/(nB-1);
                #local Count=0;
                #while (Count<nB)
                        object{PotBalcon
                        translate x*(-xB+eB+(Count*iB))
                        }
                #local Count=Count+1;
                #end
                                                  
                #if (zB>0)
                        union{
                                box{<-xB-eB,0,-eB*2>,<-xB+eB,eB,zB>}
                                box{<-xB,-eB*2,-eB>,<-xB+eB,0,zB>}
                                box{<xB-eB,0,-eB*2>,<xB+eB,eB,zB>}
                                box{<xB-eB,-eB*2,-eB>,<xB,0,zB>}
                                translate y*yB
                        }                                                        
                        #local Count=1;
                        #while (Count*iB<zB)                      
                                object{PotBalcon translate <xB-eB,0,iB*Count>}
                                object{PotBalcon translate <-xB+eB,0,iB*Count>}
                                #local Count=Count+1;
                        #end
                #end
                translate -z*zB                                                                                 
                
        #break
        #case (6)
        // Vertical bars
                union{
                        box{<-xB-eB,0,-eB*2>,<xB+eB,eB,eB>}        
                        box{<-xB,-eB*2,-eB>,<xB,0,eB>}        
                        translate y*yB
                }                    
                #local iB=(xB-eB)*2/(nB-1);
                #local Count=0;
                #while (Count<nB)
                        cylinder{0,y*(yB-2*eB),eB
                        translate x*(-xB+eB+(Count*iB))
                        }
                #local Count=Count+1;
                #end
                                                  
                #if (zB>0)
                        union{
                                box{<-xB-eB,0,-eB*2>,<-xB+eB,eB,zB>}
                                box{<-xB,-eB*2,-eB>,<-xB+eB,0,zB>}
                                box{<xB-eB,0,-eB*2>,<xB+eB,eB,zB>}
                                box{<xB-eB,-eB*2,-eB>,<xB,0,zB>}
                                translate y*yB
                        }                                                        
                        #local Count=1;
                        #while (Count*iB<zB)                      
                                cylinder{0,y*(yB-2*eB),eB translate <xB-eB,0,iB*Count>}
                                cylinder{0,y*(yB-2*eB),eB translate <-xB+eB,0,iB*Count>}
                                #local Count=Count+1;
                        #end
                #end
                translate -z*zB
        #break
#end            
texture{T_Balcon}
}

#end


//=========================================
// mWindowCase macro
//-----------------------------------------
// It creates an window case around the windows
// 7 types available
// Type 1 : Triangle roof & side ornaments
// Type 2 : Rounded roof & side ornaments
// Type 3 : Complex square case
// Type 4 : Simple square case
// Type 5 : Triangular garret
// Type 6 : Rounded garret
// Type 7 : Sloped garret (to be used on a sloped roof)
// Type 8 : Simple ledge
//-----------------------------------------
/*
#declare TypeTF=1;      // case type
#declare xF=3;          // Half-width of window around which the case is built
#declare yF=9;          // Height of window
#declare zF=0.4;        // z thickness of case
#declare eF=0.5;        // x and y thickness of case (case width = 2*(xF+eF))
#declare zRelief=0.1;   // -z protuding of case
#declare eF2=0.5;       // multipurpose parameter !
#declare yToit=1;       // Roof height
#declare eToit=0.1;     // Roof thickness
#declare yBalcon=0.5;   // Ledge height
#declare zBalcon=0.5;   // Ledge depth
#declare T_TF=texture{T_TF1}     // case texture
#declare T_Toit=texture{T_Toit1} // roof texture
*/
// ==================================================================
// 8 window case types
//-----------------------------------------
// Type 1 : Triangle roof & side ornaments
//-----------------------------------------
//#declare WCase_1=object{mWindowCase(1,xL,yL,0.4,1,0.1,  0,1,  0,0.5,0.5,T_TF,T_Toit)}
//-----------------------------------------
// Type 2 : Rounded roof & side ornaments
//-----------------------------------------
//#declare WCase_2=object{mWindowCase(2,xL,yL,0.4,1,0.1,  0,1,  2,0.5,0.5,T_TF,T_Toit)}
//-----------------------------------------
// Type 3 : Complex square case
//-----------------------------------------
//#declare WCase_3=object{mWindowCase(3,xL,yL,0.4,1,0.1,  0,0,  0,0.5,0.5,T_TF,T_Toit)}
//-----------------------------------------
// Type 4 : Simple square case
//-----------------------------------------
//#declare WCase_4=object{mWindowCase(4,xL,yL,0.4,1,0.1,0.6,0,  0,0.5,0.5,T_TF,T_Toit)}
//-----------------------------------------
// Type 5 : Triangular garret
//-----------------------------------------
//#declare WCase_5=object{mWindowCase(5,xL,yL, 25,1,0.1,0.2,2,0.1,0.5,0.5,T_TF,T_Toit)}
//-----------------------------------------
// Type 6 : Rounded garret
//-----------------------------------------
//#declare WCase_6=object{mWindowCase(6,xL,yL, 25,1,0.1,0.2,2,0.1,0.5,0.5,T_TF,T_Toit)}
//-----------------------------------------
// Type 7 : Sloped garret (to be used on a sloped roof)
//-----------------------------------------
//#declare WCase_7=object{mWindowCase(7,xL,yL, 10,1,0.1,0.2,7,0.1,1,0.5,T_TF,T_Toit)}
//-----------------------------------------
// Type 8 : Simple ledge
//-----------------------------------------

#macro mWindowCase(typeTF,xF,yF,zF,eF,zRelief,eF2,yToit,eToit,yBalcon,zBalcon,T_TF,T_Toit)
union{
#local xToit=sqrt((yToit*yToit)+(xF+eF)*(xF+eF));

#switch (typeTF)
//-----------------------------------------
// Type 1 : Triangle roof & side ornaments
//-----------------------------------------
#case (1)       
#local rToit=(yToit*yToit+xF*xF)/(2*yToit);
        difference{
                box{<-xF-eF,0,-zRelief*0.5>,<xF+eF,yF+2*yToit,zF>}
                cylinder{-xF*x*2,xF*x*2,zRelief scale <1,0.5,1> translate y*yF/5}                
                cylinder{-xF*x*2,xF*x*2,zRelief scale <1,0.5,1> translate y*2*yF/5}                
                cylinder{-xF*x*2,xF*x*2,zRelief scale <1,0.5,1> translate y*3*yF/5}                
                cylinder{-xF*x*2,xF*x*2,zRelief scale <1,0.5,1> translate y*4*yF/5}                
                cylinder{-xF*x*2,xF*x*2,zRelief scale <1,0.5,1> translate y*yF}                
                box{<-xF,0,-1>,<xF,yF,zF*3>}                                 
                intersection{
                        box{<-xF,yF,-1>,<xF,yF+yToit,zF*0.9>}        
                        cylinder{-z,z*zF*0.9,rToit translate y*(yF+yToit-rToit)}
                }
        }
        union{
                        
                union{
                        difference{
                                prism{linear_spline 0,1,5,<-xF/5,-yToit*0.5>,<-xF/3,yToit*3>,<xF/3,yToit*3>,<xF/5,-yToit*0.5>,<-xF/5,-yToit*0.5>}
                                sphere{0,1 scale <1.5,zRelief,2>*yToit*0.6 translate y translate z*yToit*1.5}
                        }
                        sphere{0,1 scale <1.5,zRelief,2>*yToit*0.4 translate y translate z*yToit*1.5}
                        torus{1,0.2 scale <1.5,zRelief,2>*yToit*0.65 translate y translate z*yToit*1.5}
                        rotate x*-90 scale <1,1,zRelief+zF> translate y*(yToit*0.5) translate z*zF
                }
                prism{linear_spline 0,1,10,<-xF-eF,0>,<-xF+eF,3*yToit>,<xF-eF,3*yToit>,<xF+eF,0>,<-xF-eF,0>,
                <-xF,0>,<(-xF+eF)*xF/(xF+eF),3*yToit*xF/(xF+eF)>,<(xF-eF)*xF/(xF+eF),3*yToit*xF/(xF+eF)>,<xF,0>,<-xF,0>
                rotate x*-90 scale <1,1,zF+zRelief*0.5> translate y*yToit*2 translate z*zF
                }
                translate y*yF                                                       
        }       
        box{<-xF-eF,-yBalcon*0.5,-zBalcon-zRelief*0.5>,<xF+eF,0,zF>}
        box{<-xF-eF*0.5,-yBalcon,-zBalcon*0.5-zRelief*0.5>,<xF+eF*0.5,0,zF>}
        
#break
//-----------------------------------------
//Type 2 : Rounded roof & side ornaments
//-----------------------------------------
// eToit is the thickness of the decorative arc
//-----------------------------------------
#case (2)
#local rToit=(yToit*yToit+xF*xF)/(2*yToit);
#local tetaToit=degrees(asin(xF/rToit));
        difference{
                union{
                        box{<-xF-eF,0,-zRelief*0.5>,<-xF,yF,zF>}
                        box{<xF,0,-zRelief*0.5>,<xF+eF,yF,zF>}
                }
                cylinder{-xF*x*2,xF*x*2,zRelief scale <1,0.5,1> translate y*yF/4} 
                cylinder{-xF*x*2,xF*x*2,zRelief scale <1,0.5,1> translate y*2*yF/4}                
                cylinder{-xF*x*2,xF*x*2,zRelief scale <1,0.5,1> translate y*3*yF/4}                
                cylinder{-xF*x*2,xF*x*2,zRelief scale <1,0.5,1> translate y*yF}                
        }
        box{<-xF-eF,-yBalcon*0.5,-zBalcon-zRelief*0.5>,<xF+eF,0,zF>}
        box{<-xF-eF*0.5,-yBalcon,-zBalcon*0.5-zRelief*0.5>,<xF+eF*0.5,0,zF>}
       difference{
                cylinder{-zRelief*0.5*z,z*zF,rToit+eToit}
                cylinder{-z,z*zF*3,rToit}
                
                cylinder{0,(rToit+2*eToit)*y, zRelief scale <0.5,1,1> rotate -z*tetaToit}
                cylinder{0,(rToit+2*eToit)*y, zRelief scale <0.5,1,1> rotate -z*(tetaToit-2*tetaToit/5)}
                cylinder{0,(rToit+2*eToit)*y, zRelief scale <0.5,1,1> rotate -z*(tetaToit-4*tetaToit/5)}
                cylinder{0,(rToit+2*eToit)*y, zRelief scale <0.5,1,1> rotate -z*(tetaToit-6*tetaToit/5)}
                cylinder{0,(rToit+2*eToit)*y, zRelief scale <0.5,1,1> rotate -z*(tetaToit-8*tetaToit/5)}
                cylinder{0,(rToit+2*eToit)*y, zRelief scale <0.5,1,1> rotate -z*(tetaToit-10*tetaToit/5)}
                plane{x,0 rotate z*tetaToit}
                plane{x,0 rotate -z*tetaToit inverse}
                
                translate y*(yF+yToit-rToit)
                
        }
        
#break
//-----------------------------------------
// Type 3 : complex square case
//-----------------------------------------
#case (3)
#local elTF3=difference{
        box{<0,-xF-yF,-zRelief*0.5>,<eF,xF+yF,zF>}
        box{<eF*0.2,(-xF-yF)*2,-zRelief*4>,<eF*2,(xF+yF)*2,0>}
        box{<eF*0.5,(-xF-yF)*2,-zRelief*4>,<eF*2,(xF+yF)*2,zF*0.1>}
        cylinder{(-xF-yF)*2*y,(xF+yF)*2*y,eF*0.15 translate <eF*0.35,0,0>} 
        cylinder{(-xF-yF)*2*y,(xF+yF)*2*y,eF*0.15 translate <eF*0.75,0,eF*0.2>} 
}                                                         

        intersection{
                object{elTF3}
                plane{y,0 rotate -z*45 translate <eF,yF,0>}        
                plane{y,0 inverse}        
                translate -x*(xF+eF)
        }
        intersection{
                object{elTF3}
                plane{y,0 rotate -z*45 translate <eF,yF,0>}        
                plane{y,0 inverse}        
                translate -x*(xF+eF)
                scale <-1,1,1>
        }
        
        intersection{
                object{elTF3}
                plane{y,0 rotate -z*45 translate <eF,xF,0>}        
                plane{y,0 rotate z*45 translate <eF,-xF,0> inverse}        
                rotate -z*90
                translate y*(yF+eF)
        }
                        
        box{<-xF-eF,-yBalcon*0.5,-zBalcon-zRelief*0.5>,<xF+eF,0,zF>}
        box{<-xF-eF,-yBalcon,-zBalcon*0.5-zRelief*0.5>,<xF+eF,0,zF>}

#break
//-----------------------------------------
// Type 4 : simple square case
//-----------------------------------------
// eF2 is the thickness of the superior border
//-----------------------------------------
#case (4)
        difference{
                box{<-xF-eF,0,-zRelief>,<xF+eF,yF+eF2,zF>} 
                box{<-xF,-1,-zRelief*3>,<xF,yF,zF*3>} 
        }                       
        box{<-xF-eF,-yBalcon*0.5,-zBalcon-zRelief*0.5>,<xF+eF,0,zF>}
        box{<-xF-eF,-yBalcon,-zBalcon*0.5-zRelief*0.5>,<xF+eF,0,zF>}

#break
//-----------------------------------------
// Type 5 : triangle garret
//-----------------------------------------
#case (5)
#local xToit=sqrt((yToit*yToit)+(xF+eF)*(xF+eF));
        box{<-xF,0,-zRelief*2>,<xF,eF2,0> translate y*(yF+eF-eF2*2)}
        difference{
                box{<-xF-eF,0,-zRelief>,<xF+eF,yF+eF,zF>} 
                box{<-xF-eF2,-1,-zRelief*3>,<xF+eF2,yF+eF2,0>} 
                box{<-xF,-1,-zRelief*3>,<xF,yF,zF*3>} 
        }   
        union{                            
                intersection{
                        union{                                      
                                union{
                                        box{<-xToit*1.1,0,-zRelief*2>,<2,eToit*0.5,zF>}
                                        box{<-xToit*1.11,0,-zRelief*3>,<2,eToit,zF> translate y*eToit*0.5}
                                        rotate z*degrees(acos((xF+eF)/xToit))
                                        texture{T_Toit}

                                }                     
                                box{<-xF,0,zRelief>,<xF,eF2,zRelief*2> translate -y*yToit}
                                intersection{
                                        difference{
                                                box{<-xToit,-yToit,0>,<0,0,zF>}
                                                box{<-xToit*2,-yToit,-1>,<0,-eF,zRelief>}
                                                box{<-xToit*2,-yToit,-1>,<0,-eF-eF2,zRelief*2>}
                                                rotate z*degrees(acos((xF+eF)/xToit)) translate y*yToit
                                        }
                                        plane{y,0 inverse}         
                                        translate -y*yToit
                                        }
                                }                         
                        plane{x,0}
                  }

                intersection{
                        union{
                                union{
                                        box{<-xToit*1.1,0,-zRelief*2>,<2,eToit*0.5,zF>}
                                        box{<-xToit*1.11,0,-zRelief*3>,<2,eToit,zF> translate y*eToit*0.5}
                                        rotate z*degrees(acos((xF+eF)/xToit))
                                        texture{T_Toit}
                                }
                                box{<-xF,0,zRelief>,<xF,eF2,zRelief*2> translate -y*yToit}
                                intersection{
                                        difference{
                                                box{<-xToit,-yToit,0>,<0,0,zF>}
                                                box{<-xToit*2,-yToit,-1>,<0,-eF,zRelief>}
                                                box{<-xToit*2,-yToit,-1>,<0,-eF-eF2,zRelief*2>}
                                                rotate z*degrees(acos((xF+eF)/xToit)) translate y*yToit
                                        }
                                        plane{y,0 inverse}         
                                        translate -y*yToit
                                        }
                                }                         
                        plane{x,0}
                        scale <-1,1,1>
                  }
                        

                translate <0,yF+eF+yToit,-zRelief>
        }                    
        box{<-xF-eF,-yBalcon*0.5,-zBalcon-zRelief*0.5>,<xF+eF,0,zF>}
        box{<-xF-eF,-yBalcon,-zBalcon*0.5-zRelief*0.5>,<xF+eF,0,zF>}

#break
//-----------------------------------------
// Type 6 : rounded garret
//-----------------------------------------
#case (6)
#local rToit=((xF+eF)*(xF+eF)+yToit*yToit)/(2*yToit);
        box{<-xF,0,-zRelief*2>,<xF,eF2,0> translate y*(yF+eF-eF2*2)}
        difference{
                box{<-xF-eF,0,-zRelief>,<xF+eF,yF+eF,zF>} 
                box{<-xF-eF2,-1,-zRelief*3>,<xF+eF2,yF+eF2,0>} 
                box{<-xF,-1,-zRelief*3>,<xF,yF,zF*3>} 
        }   
        union{                                              
                union{
                        difference{     
                                cylinder{-z*zRelief*2,z*zF,rToit+eToit translate -y*(rToit-yToit)}
                                cylinder{-z*zF*2,z*zF*2,rToit translate -y*(rToit-yToit)}
                                plane{y,0} 
                                texture{T_Toit}
                        }
                        difference{
                                cylinder{-z*zRelief*3,z*zF,rToit+eToit*2 translate -y*(rToit-yToit)}
                                cylinder{-z*zF*2,z*zF*2,rToit+eToit translate -y*(rToit-yToit)}
                                plane{y,0}
                                texture{T_Toit}
                        }

                }
                box{<-xF,0,0>,<xF,eF2,zRelief*2>}
                difference{
                        intersection{
                                cylinder{-zRelief*z,zF*z,rToit translate -y*(rToit-yToit)}
                                plane{y,0 inverse}
                        }                        
                        intersection{
                                cylinder{-zF*z,0,rToit translate -y*(rToit-yToit)}
                                plane{y,0 inverse}
                                scale (rToit-eF)/rToit
                        }                        
                        intersection{
                                cylinder{-zF*z,zRelief*z,rToit translate -y*(rToit-yToit)}
                                plane{y,0 inverse}
                                scale (rToit-eF-eF2)/rToit
                        }          
                }              
                translate y*(yF+eF)
        }        
                        
        box{<-xF-eF,-yBalcon*0.5,-zBalcon-zRelief*0.5>,<xF+eF,0,zF>}
        box{<-xF-eF,-yBalcon,-zBalcon*0.5-zRelief*0.5>,<xF+eF,0,zF>}
#break
//-----------------------------------------
// Type 7 : sloped garret
//-----------------------------------------
#case (7)
        #local zToit=zF/cos(atan2(yToit,zF));
        union{                          
                union{
                        box{<-xF-eF2-eF,0,-eF2*2>,<xF+eF2+eF,eF2,zToit>}
                        cylinder{-eF2*2*z,zToit*z,eF2 translate x*(2*(xF+eF)/3-xF-eF) translate y*eF2}
                        cylinder{-eF2*2*z,zToit*z,eF2 translate x*(4*(xF+eF)/3-xF-eF) translate y*eF2}
                        texture{T_Toit}
                }
                box{<-xF-eF,-yF,0>,<-xF,0,zToit>}
                box{<xF,-yF,0>,<xF+eF,0,zToit>}
                rotate -x*degrees(atan2(yToit,zF))
                translate y*(yF+eF)
        }
        difference{
                box{<-xF-eF,0,-zRelief>,<xF+eF,yF+eF,zF>} 
                box{<-xF-eF2,-1,-zRelief*3>,<xF+eF2,yF+eF2,0>} 
                box{<-xF,-1,-zRelief*3>,<xF,yF,zF*3>} 
        }   
                        
        box{<-xF-eF,-yBalcon*0.5,-zBalcon-zRelief*0.5>,<xF+eF,0,zF>}
        box{<-xF-eF,-yBalcon,-zBalcon*0.5-zRelief*0.5>,<xF+eF,0,zF>}
#break
#case (8)
//-----------------------------------------
// Type 8 : simple ledge
//-----------------------------------------
        box{<-xF-eF,-yBalcon*0.5,-zBalcon-zRelief*0.5>,<xF+eF,0,zF>}
        box{<-xF-eF,-yBalcon,-zBalcon*0.5-zRelief*0.5>,<xF+eF,0,zF>}

#break
#end        
texture{T_TF}
}
#end

//=========================================
// mShutter macro
//-----------------------------------------
// It creates different types of shutters
// 6 types available
// Type 1 : simple shutter on vertical hinge
// Type 2 : simple shutter on horizontal hinge
// Type 3 : classic 2 panes shutter (left and right)
// Type 4 : classic 4 panes shutter (left and right)
// Type 5 : slatted shutter (venetian blind)
// Type 6 : cloth blind
//-----------------------------------------
/*
#declare typeV=3;       // Shutter type
#declare xV1=3.5;       // half window width
#declare yV=10;         // shutter height
#declare zV=0.2;        // shutter thickness (or vertical opening height in typeV=6)
#declare eV=0.4;        // radius of inner pane bars
#declare nlV=20;        // number of slats (should be even)
                        // number of slats also controls shutter opening for type 5
#declare tetalV=175;    // slats rotation angle
#declare tetaVG=155;    // left or single pane rotation angle (0=closed)
#declare tetaVD=165;    // right pane rotation angle (0=closed) 
#declare yHinge=0.7;     // half-height of shutter hinge
#declare rHinge=0.1;     // hinge radius
#declare sRd=0.01;      // randomness amount for :
                        // shutter positionning (type 1 to 4)
                        // slate positionning (type 5)
                        // for cloth wave (type 6)
#declare rd=seed(343);  // random stream
#declare T_Volet=texture{T_Volet1}     // shutter texture
*/
// ==================================================================
// 2 x 6 shutter types (closed or open)
// Type 1 to 4 : change the angle values for opening
//-----------------------------------------
// Type 1 : simple shutter on vertical hinge
//-----------------------------------------
// closed
//#declare Shutter_1_c=object{mShutter(1,xL,yL,0.2,0.3,20,5,2,0,0.7,0.1,rd,0.05,T_V1) }
// open
//#declare Shutter_1_o=object{mShutter(1,xL,yL,0.2,0.3,20,175,175,0,0.7,0.1,rd,0.01,T_V1)}
//-----------------------------------------
// Type 2 : simple shutter on horizontal hinge
//-----------------------------------------
// closed
//#declare Shutter_2_c=object{mShutter(2,xL,yL,0.2,0.3,20,5,1,0,0.7,0.1,rd,0.01,T_V1)}
// half-open
//#declare Shutter_2_o=object{mShutter(2,xL,yL,0.2,0.3,20,5,61,0,0.7,0.1,rd,0.01,T_V1)}
//-----------------------------------------
// Type 3 : classic 2 panes shutter (left and right)
//-----------------------------------------         
// closed
//#declare Shutter_3_c=object{mShutter(3,xL,yL,0.2,0.3,20,5,5,6,0.7,0.1,rd,0.5,T_V1)}
// open
//#declare Shutter_3_o=object{mShutter(3,xL,yL,0.2,0.3,20,175,155,165,0.7,0.1,rd,0.5,T_V1)}
//-----------------------------------------
// Type 4 : classic 4 panes shutter (left and right)
//-----------------------------------------         
// closed
//#declare Shutter_4_c=object{mShutter(4,xL,yL,0.2,0.3,20,5,5,6,0.7,0.1,rd,0.5,T_V1)}
// part open
//#declare Shutter_4_o=object{mShutter(4,xL,yL,0.2,0.3,20,5,75,56,0.7,0.1,rd,0.5,T_V1)}
//-----------------------------------------
// Type 5 : slatted shutter (Venetian blind)
//-----------------------------------------         
// closed
//#declare Shutter_5_c=object{mShutter(5,xL,yL,0.5,0.1,15,0,0,0,0.4,0.2,rd,0.1,T_V2)}
// part open
//#declare Shutter_5_o=object{mShutter(5,xL,yL,0.5,0.1,5,0,0,0,0.4,0.2,rd,0.1,T_V2)}
//-----------------------------------------
// Type 6 : cloth blind
//-----------------------------------------         
// closed
//#declare Shutter_6_c=object{mShutter(6,xL,yL,yL*0.8,0.1,0,0,0,0,0,0,rd,0.3,T_V2)}
// part open
//#declare Shutter_6_o=object{mShutter(6,xL,yL,yL*0.1,0.1,0,0,0,0,0,0,rd,0.5,T_V2)}
//-----------------------------------------         
#macro mShutter(typeV,xV1,yV,zV,eV,nlV,tetalV,tetaVG,tetaVD,yHinge,rHinge,rd,sRd,T_Volet)
union{
#switch (typeV)
        #case (3)
                #local xV=xV1;
        #break
        #case (4)
                #local xV=xV1*0.5;
        #break
        #else
                #local xV=2*xV1;
        
#end                                               
#if (typeV<6)
#local Hinges=union{
        union{
                union{cylinder{0,y*yHinge,rHinge} sphere{y*yHinge,rHinge} translate y*rHinge*0.2}
                union{cylinder{0,-y*yHinge,rHinge} sphere{-y*yHinge,rHinge} translate -y*rHinge*0.2}
                translate y*yV/4
        }
        union{
                union{cylinder{0,y*yHinge,rHinge} sphere{y*yHinge,rHinge} translate y*rHinge*0.2}
                union{cylinder{0,-y*yHinge,rHinge} sphere{-y*yHinge,rHinge} translate -y*rHinge*0.2}
                translate y*3*yV/4
        }
}            
#end
#switch (typeV)
// classic pane
#range (1,4)
        #local PanVolet=union{
                difference{
                        box{<0,0,0>,<xV,yV,zV>}
                        box{<eV,eV,-1>,<xV-eV,yV-eV,zV+eV>}
                }                          
                box{<eV,-eV*0.5,0>,<xV-eV,eV*0.5,zV> translate y*yV*0.5}
                #local elV=(yV-3*eV)/nlV;
                #local Count=0;                                                               
                #local zlV=min(zV*0.4,abs(sin(radians(tetalV))));
                mesh{
                        #while (Count<nlV)          
                                #if (Count<nlV/2)
                                #local ylV=eV+elV*0.5*(2*Count+1);
                        #else
                                #local ylV=2*eV+elV*0.5*(2*Count+1);
                        #end
                        triangle{<eV,-cos(radians(tetalV))*elV/2+ylV,-zlV>,
                         <xV-eV,cos(radians(tetalV))*elV/2+ylV,zlV>,
                         <eV,cos(radians(tetalV))*elV/2+ylV,zlV>}
                        triangle{<eV,-cos(radians(tetalV))*elV/2+ylV,-zlV>,
                         <xV-eV,cos(radians(tetalV))*elV/2+ylV,zlV>,
                         <xV-eV,-cos(radians(tetalV))*elV/2+ylV,-zlV>}
                        #local Count=Count+1;
                #end                                                                       
                translate z*zV*0.5
                }
        }
#break        
// slatted pane
#case (5)
        #local PanVolet=union{
                #local Latte=difference{
                                cylinder{0,xV*x,zV/2}
                                cylinder{-x,xV*2*x,0.9*zV/2}
                                plane{z,0 inverse}
                                scale <1,0.9,0.4>
                }       
                cylinder{y*yV,y*(yV-zV*nlV),eV translate <xV/4,0,0>}
                cylinder{y*yV,y*(yV-zV*nlV),eV translate <3*xV/4,0,0>}
                #local Count=0;
                #while (Count<nlV)           
                        object{Latte translate x*xV*0.5 rotate z*(0.5-rand(rd))*4*sRd translate -x*xV*0.5 translate y*(yV-(Count+0.5)*zV)}
                        #local Count=Count+1;
                #end
        }
#break   
// cloth pane
#case (6)
        #local PanVolet=mesh{            
                #local nPanVolet1=<sRd*(0.5-rand(rd)),sRd*(0.5-rand(rd)),-1>;
                #local nPanVolet2=<sRd*(0.5-rand(rd)),sRd*(0.5-rand(rd)),-1>;
                #local nPanVolet3=<sRd*(0.5-rand(rd)),sRd*(0.5-rand(rd)),-1>;
                #local nPanVolet4=<sRd*(0.5-rand(rd)),sRd*(0.5-rand(rd)),-1>;
                #local nPanVolet5=<sRd*(0.5-rand(rd)),sRd*(0.5-rand(rd)),-1>;
                #local nPanVolet6=<sRd*(0.5-rand(rd)),sRd*(0.5-rand(rd)),-1>;
//                triangle{<0,0,0>,<xV,0,0>,<xV,zV,0>}
//                triangle{<0,0,0>,<0,zV,0>,<xV,zV,0>}
                smooth_triangle{<0,0,0>,nPanVolet1,<xV,0,0>,nPanVolet2,<xV,zV*0.5,0>,nPanVolet3}
                smooth_triangle{<0,0,0>,nPanVolet1,<0,zV*0.5,0>,nPanVolet4,<xV,zV*0.5,0>,nPanVolet3}
                smooth_triangle{<0,zV*0.5,0>,nPanVolet4,<xV,zV*0.5,0>,nPanVolet3,<xV,zV,0>,nPanVolet6}
                smooth_triangle{<0,zV*0.5,0>,nPanVolet4,<0,zV,0>,nPanVolet5,<xV,zV,0>,nPanVolet6}
                translate y*(yV-zV)
        }

#break
#end
#switch (typeV)
        // simple shutter on vertical hinge
        #case (1)
                object{PanVolet}
                object{Hinges translate <-rHinge,0,0>}
                translate -y*3*yV/4
                rotate -z*sRd*5
                rotate y*tetaVG
                translate y*3*yV/4
                translate -x*xV1                                
                                
        #break
        // simple shutter on horizontal hinge
        #case (2)
                cylinder{<xV-eV/2,(-yV+eV/2)*cos(radians(tetaVG))+(yV+eV/2),(-yV+eV/2)*sin(radians(tetaVG))>,
                        <xV+eV/2,eV/2,0>,
                        eV*0.3          
                }                        
                sphere{<xV-eV/2,(-yV+eV/2)*cos(radians(tetaVG))+(yV+eV/2),(-yV+eV/2)*sin(radians(tetaVG))>,
                        eV*0.3          
                }                        
                cylinder{<eV/2,(-yV+eV/2)*cos(radians(tetaVG))+(yV+eV/2),(-yV+eV/2)*sin(radians(tetaVG))>,
                        <-eV/2,eV/2,0>,
                        eV*0.3          
                }                        
                sphere{<eV/2,(-yV+eV/2)*cos(radians(tetaVG))+(yV+eV/2),(-yV+eV/2)*sin(radians(tetaVG))>,
                        eV*0.3          
                }                        
                union{
                        object{PanVolet}
                        object{Hinges translate -y*yV*0.5 rotate z*90 scale <xV/yV,1,1> translate <xV*0.5,yV,0>}
                        translate -y*yV
                        rotate x*tetaVG
                        translate y*yV
                }
                translate -x*xV1                                
        #break
        // classic 2 panes shutter
        #case (3)
                union{
                        object{PanVolet}
                        object{Hinges translate <-rHinge,0,0>}
                        translate -y*3*yV/4
                        rotate -z*sRd*5*rand(rd)
                        rotate y*tetaVG
                        translate y*3*yV/4
                        translate -xV*x
                }       
                union{         
                        object{PanVolet}
                        object{Hinges translate <-rHinge,0,0>}
                        translate -y*3*yV/4
                        rotate -z*sRd*5*rand(rd)
                        rotate y*tetaVD
                        translate y*3*yV/4
                        translate -xV*x
                        scale <-1,1,1>
                }                
        #break
        // classic 4 panes shutter
        #case (4)
                union{
                        object{PanVolet}
                        object{Hinges translate <-rHinge,0,zV>}
                        union{
                                object{PanVolet}
                                object{Hinges translate <-rHinge*0.5,0,0>}
                                rotate y*tetaVG*2
                                translate x*xV
                        }
                        translate -z*zV
                        translate -y*3*yV/4
                        rotate -z*sRd*5*rand(rd)
                        rotate -y*tetaVG
                        translate y*3*yV/4
                        translate -xV*x*2
                }
                union{
                        object{PanVolet}
                        object{Hinges translate <-rHinge,0,zV>}
                        union{
                                object{PanVolet}
                                object{Hinges translate <-rHinge*0.5,0,0>}
                                rotate y*tetaVD*2
                                translate x*xV
                        }
                        translate -z*zV
                        translate -y*3*yV/4
                        rotate -z*sRd*5*rand(rd)
                        rotate -y*tetaVD
                        translate y*3*yV/4
                        translate -xV*x*2
                        scale <-1,1,1>
                }
                        
        #break
        // slatted shutter
        #case (5)
                object{PanVolet}
                object{Hinges translate -y*yV*0.5 rotate z*90 scale <xV/yV,1,1> translate <xV*0.5,yV,0>}
                translate -x*xV1                                
        #break
        // cloth shutter
        #case (6)
                object{PanVolet}
                union{
                        cylinder{-eV*x,x*(xV+eV),eV}
                        cylinder{-eV*1.5*x,-eV*x,eV*1.5}
                        cylinder{eV*1.5*x,eV*x,eV*1.5 translate x*xV}
                        translate y*yV
                }
                union{
                        cylinder{-eV*x,x*(xV+eV),eV}
                        cylinder{-eV*1.5*x,-eV*x,eV*1.5}
                        cylinder{eV*1.5*x,eV*x,eV*1.5 translate x*xV}
                        translate y*(yV-zV)
                }
                translate -x*xV1                                
                
        #break
#end            
texture{T_Volet}
}
#end
