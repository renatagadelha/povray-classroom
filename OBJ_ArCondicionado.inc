#include "colors.inc"

/*
camera {
  location <0,1,-4>
  look_at <0,0,0>
}
 
background { LightSteelBlue }

light_source { <500,500,-1000> color White}


plane {
  y, 0   
  pigment { checker Green Black }
}
*/


#local AL = 4; //arcondicionado largura
#local AA = 1.2; //arcondicionado altura
#local AP = 1; //arcondicionado profundidade

#declare ArCondicionado =
union{
  difference {
    intersection { //arrendodamento lateral
      box {
        <-AL/2, 0, -AP/2> <AL/2, AA, AP/2>
      }
      sphere {
        <0,0,2.07>, 3
      }  
    }   
    
    
    difference { //arrendodamento/corte de baixo
      box {
        <-AL, 0, -1> <AL, 1,1>
        rotate <0, 0, 0>
      } 
      cylinder { 
        <-AL,1,0.2>, <AL,1,0.2>, 0.8
      } 
      translate<0,-0.15,0>
         
    }
    
    cylinder { //saida de ar
      <(-AL/2)+0.5,0.2,-0.5>, <(AL/2)-0.5,0.2,-0.5>, 0.3
     // rotate <30, 0, 0>
    } 

  }  
  
  box {  //palheta
    <(-AL/2)+0.5, -0.1, -0.5> <(AL/2)-0.5, 0.4, -0.53>
    rotate <45, 0, 0>   
  }
  
  
  
   
  sphere {  //luz ligado
    <1.2,0.6,-0.48>, 0.04
     pigment{ color Green }
     finish{ambient 1 reflection 0.1}
  } 
      
              
         
  pigment{ color White }
  finish {phong 0.8 reflection 0.1}
}
 

   
//chamada
//object {ArCondicionado} 