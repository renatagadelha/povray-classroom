//#include "colors.inc"

#include "OBJ_PC.inc"
#include "EXT_Chair_s00.inc"

/*
camera {
  location <0,6,-5>
  look_at <0,2,0>
}
 
background { LightSteelBlue }

light_source { <500,500,-1000> color White}
light_source { <0,50,-5> color White}


plane {
  y, 0   
  pigment { checker Green White }
}
 */ 


// table dimensions
#local A = 2.5; // altura
#local LX = 5; // largura
#local LZ = 3; // profundidade
#local R = 0.1; // raio perna

#local LPC = 3.8; //largura do espaço para o pc

#declare Bancada =
union{
   // pés  
  cylinder{<0,0,0>,<0,A,0>, R       
           translate<(-LPC/2)+R/2,0,-LZ/2+R>} //frente 3  
  cylinder{<0,0,0>,<0,A,0>, R
           translate<(LPC/2)+R/2,0,-LZ/2+R>} //frente 4
  cylinder{<0,0,0>,<0,A,0>, R
           translate<(-LPC/2)+R/2,0,LZ/2+R>} //atrás 3  
  cylinder{<0,0,0>,<0,A,0>, R
           translate<(LPC/2)+R/2,0,LZ/2+R>} //atrás 4
  
  // tampo
  box{ <(-LX/2)-0.1,-0.15,(-LZ/2)-0.1>,<(LX/2)+0.1,0,(LZ/2)+0.1>
       translate<0,A,0> }

  pigment{ color rgb<0.75,0.5,0.3>*0.3}
}// end of union 'Table_01'


#declare BancadaPcProf = union {
  //Bancada
  object{Bancada}    

  object { PC
    translate<0,2*A,0>
    scale 0.5
    
  }
  
  //Cadeiras
  #local CA = 3; //cadeira altura
  #local CAA = 1.5; //cadeira assento altura
  #local CL = 0.7; //cadeira metade largura
  #local CR = 0.1; //cadeira pé raio 
  
  #local CDM = -1.3; //cadeira distancia mesa
  
  object { 
    Chair_s00(CA,CAA,CL,CR)     //cadeira 1
    pigment{ color rgb<0.75,0.5,0.3>*0.3}
    scale <0,0,-1>
    translate<0,0,CDM>
  }
}

//chamada
//object {BancadaPcProf}