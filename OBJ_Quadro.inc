#include "colors.inc"
#include "textures.inc"

/*
camera {
  location <0,1,-7>
  look_at <0,0,0>
}
 
background { LightSteelBlue }

light_source { <500,500,-1000> color White}


plane {
  y, 0   
  pigment { checker Green Black }
} 
*/
 
#local QL = 8; //arcondicionado largura
#local QA = 2; //arcondicionado altura

#declare Quadro =
union{
      box { //quadro
        <-QL/2, 0, 0> <QL/2, QA, -0.2>
      }
      
      difference { //porta-caneta
        box {
          <-QL/2, 0, -0.4> <QL/2, 0.1, 0>
        }
        box {
          <-QL, 0.05, -0.35> <QL, 0.5, 0>
        }
        texture{ Polished_Chrome}
      }
                   
           
      text {
        ttf "cyrvetic.ttf" "IFSP / 2018" 0.15, 0
        pigment { Black }
        finish {phong 0.8 reflection 0.1}
        
        translate <-2.5, 0.6, -0.21>
      }
       
  pigment{ color White }
  finish {phong 0.8 reflection 0.1}
}
 

   
//chamada
//object {Quadro} 