#include "colors.inc"

/*
camera {
  location <0,1.1,-2>
  look_at <0,1,0>
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

#declare Projetor =
union{
      difference { //pé
        sphere {
          <0,0,0>, 0.2
        }
        box {
          <-0.5, -0.5, -0.5> <0.5, 0, 0.5>
        }
      }
      
      cylinder {    //haste
        <0,0,0>, <0,0.8,0>, 0.1
      }
      cylinder {    //haste segura
        <0,0.6,0>, <0,0.8,0>, 0.2
      }
      
      
      //caixa
      intersection {
        box {
          <-0.5, 0.7, -0.5> <0.5, 1.1, 0.5>
        }
        cylinder {
          <0,0.9,-0.6>, <0,0.9,0.6>, 0.5
        }
      }
      
      
      difference { //lente externo
        cylinder {
          <-0.3,0.9,-0.6>, <-0.3,0.9,0>, 0.1
          pigment{ color Black }
          finish {phong 0.8 reflection 0.1}
        }
        cylinder {
          <-0.3,0.9,-0.7>, <-0.3,0.9,0>, 0.06
        }
      }
      
      cylinder {   //lente vidro
        <-0.3,0.9,-0.6>, <-0.3,0.9,-0.59>, 0.06
        pigment { color Cyan filter 0.7 }
        finish {phong 0.8 reflection 0.2}
      }                  
      
      sphere {  //luz desligado
        <-0.4,1.04,-0.5>, 0.025
        pigment{ color Red }
        finish{ambient 1 reflection 0.1}
      } 
        
  pigment{ color White }
  finish {phong 0.8 reflection 0.1}
}
 

   
//chamada
//object {Projetor} 