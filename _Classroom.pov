//#include "colors.inc"

#include "OBJ_ArCondicionado.inc"
#include "OBJ_Mesa.inc"  
#include "OBJ_PC.inc"    
#include "OBJ_ProjetorTeto.inc"
#include "OBJ_Quadro.inc" 
#include "EXT_library_old.inc"
#include "EXT_mwindow.pov"
#include "OBJ_Mesa_Prof.inc" 


/*camera {
  location <-5,10,0>
  look_at <5,10,0>
}*/

//camera { location <-5,10,0> look_at <5,10,0>} //teto projetor, janela 
//camera { location <5,10,0> look_at <-5,10,0>} //teto, quadro, mesa professor
//camera { location <0,10,-5> look_at <0,10,5>} //teto, lateral projetor, arcondicionado
//camera { location <0,10,-5> look_at <0,6,5>} //arcondicionado , bancadas
camera { location <10,10,-5> look_at <10,6,5>} //arcondicionado , prateleiras com livros
//camera { location <0,10,10> look_at <0,6,-5>} //lateral projeto, computadores    
//camera { location <0,40,0> look_at <0,0,0>} //topo     precisa retirar teto
 
background{rgb<0.9,0.98,1>} //céu

light_source { <500,500,-1000> color White} 

light_source { <-10,10,0> color White} //luz sala atrás
light_source { <10,10,0> color White}  //luz sala frente


#declare colWall=rgb<1,0.9,0.7>;
#declare T_Wall=
texture{pigment{gradient y 
pigment_map{[0 colWall][1.0 colWall]}}
//normal {agate 0.7}
finish{ambient 0.01 specular 0.03 roughness 0.005} scale 32 translate -y*3}


plane {
  y, 0   
  pigment { color Green }
}
 
 
//Bancada
#local BL = 3; //Largura da bancada


object {
  BancadaPc            
  scale <0,0,-1>
  translate<0,0,(-BL*3)-1.1>
}
object {
  BancadaPc
  translate<0,0,-BL/2>
}
object {
  BancadaPc
  scale <0,0,-1>
  translate<0,0,BL/2>
} 
object {
  BancadaPc
  translate<0,0,(BL*3)+1.1>
}  

//Paredes
#local PLar = 40; //parede largura lateral 
#local PAlt = 12; //parede altura
#local PProf = 0.5; //parede produndidade
#local PDis = 12; //parede lateral distancia centro   

//Janelas
// ==================================================================
// common parameters & textures
// --------------------------------------
#declare rd=seed(18908);
#declare xL=3;
#declare yL=9;
#declare T_Window1=texture{pigment{DarkTan}}         
#declare T_Window2=texture{pigment{White}}
#declare T_Glass1=texture{pigment{Clear}}
#declare T_TF=texture{pigment{rgb<1,0.9,0.8>*1.3}}
#declare T_V1=texture{pigment{SkyBlue}}
#declare T_V2=texture{pigment{rgb<1,0.8,0.5>}}            
//-----------------------------------------
// Type 4 = horizontal sliding
//-----------------------------------------
// closed
#declare Window_4_c=object{mWindow(4,xL,yL,0.2,0.3,0.1,0.1,0,0,0,0,0.5,0.1,T_Window1,T_Window2,T_Glass1)}
// part open (60%)
#declare Window_4_o1=object{mWindow(4,xL,yL,0.2,0.3,0.1,0.1,0,0,60,0,0.5,0.1,T_Window1,T_Window2,T_Glass1)}
// fully open
#declare Window_4_o2=object{mWindow(4,xL,yL,0.2,0.3,0.1,0.1,0,0,100,0,0.5,0.1,T_Window1,T_Window2,T_Glass1)}
//-----------------------------------------
// Type 6 : cloth blind
//-----------------------------------------         
// closed
#declare Shutter_6_c=object{mShutter(6,xL*0.9,yL,yL*0.8,0.1,0,0,0,0,0,0,rd,0.3,T_V2)}
// half open
#declare Shutter_6_h=object{mShutter(6,xL*0.9,yL,yL*0.5,0.1,0,0,0,0,0,0,rd,0.5,T_V2)}
// open
#declare Shutter_6_o=object{mShutter(6,xL*0.9,yL,yL*0.1,0.1,0,0,0,0,0,0,rd,0.5,T_V2)}
// ==================================================================

//Paredes
union {
  box {   //lateral direita
    <-PLar/2, 0, -PProf/2> <PLar/2, PAlt, PProf/2>
    translate<0,0,PDis>
  }
  box {   //lateral esquerda
    <-PLar/2, 0, -PProf/2> <PLar/2, PAlt, PProf/2> 
    translate<0,0,-PDis>
  }
  
  box {   //frente
    <-PLar/2, 0, -PDis> <(-PLar/2)+PProf, PAlt, PDis>
  }
  
  //parede fundo
  difference { 
    box {   //fundo
      <PLar/2, 0, -PDis> <(PLar/2)-PProf, PAlt, PDis> 
    }
    box{  //buraco janela esquerda
      <-xL+0.22,0.22,-10>,<xL-0.22,yL,100>
      rotate y*90
      translate <(PLar/2),1,PDis-8>
    }  
    box{  //buraco janela direita
      <-xL+0.22,0.22,-10>,<xL-0.22,yL,100>
      rotate y*90
      translate <(PLar/2),1,-PDis+8>
    }
    
  }
  
  //Janela esquerda
  union{
          object{Window_4_c translate z*0.5}
  //        object{Shutter_6_c}
          object{Shutter_6_o}
  
  rotate y*90
  translate <(PLar/2),1,PDis-8>
  } 
  
  //Janela direita
  union{
          object{Window_4_c translate z*0.5}
          object{Shutter_6_c}
  //        object{Shutter_6_o}
  
  rotate y*90
  translate <(PLar/2),1,-PDis+8>
  }
  
 box {   //teto
    <-PLar/2, PAlt, -PDis> <PLar/2, PAlt+PProf,PDis>
  }  
  
  texture{T_Wall}
}

box {   //chao
    <-PLar/2, 0, -PDis> <PLar/2, 0.1,PDis>
    pigment { checker Silver White }
  }
  

//Quadro
object {
  Quadro   
  rotate<0,-90,0>
  scale<2,2,2>
  translate<(-PLar/2)+0.3,PAlt/3,0>
}


//Mesa Professor
object {
  BancadaPcProf
  rotate<0,90,0>
  translate<(-PLar/2)+5,0,-PDis+4>
}  

//Projetor
object {
  Projetor  
  rotate<180,-90, 0>
  translate<0,PAlt,0>
} 

//Arcondicionado Esquerda
object {
  ArCondicionado   
  rotate<0,0,0>
  translate<-PLar/5,PAlt-3,PDis-0.7>
}   
 //Arcondicionado Direita
object {
  ArCondicionado   
  //rotate<0,-90,0>
  translate<PLar/5,PAlt-3,PDis-0.7>
}

//prateleiras
#declare doBooks=true; // creates the books
//#declare doBooks=false; // does not create the books
union{
    //prateleira esquerda
    #declare nShelf=5; // number of shelves
    #declare nSetMax=4;     // maximum number of book sets
    #declare slackShelf=1;  // very slack
    object{mLibrary(xLib*0.9,yLib,zLibShelf,zLibPanel,yLibPanel,yPlinth,nShelf,sdyShelf,ePlankShelf,xBook,sdxBook,sdyBook,sdzBook,typeShelf,typeBook,slackShelf,nSetMax,doBooks,T_Wood)}
    
    //prateleira
    #declare nShelf=5;
    #declare nSetMax=4;
    #declare slackShelf=1;  // lot of slack
    object{mLibrary(xLib*0.9,yLib,zLibShelf,zLibPanel,yLibPanel,yPlinth,nShelf,sdyShelf,ePlankShelf,xBook,sdxBook,sdyBook,sdzBook,typeShelf,typeBook,slackShelf,nSetMax,doBooks,T_Wood) translate x*1.2*xLib}
    

    texture{T_Wood}
    //rotate y*30
    scale<2,2,3>
    translate<(PLar/2)-9,0,PDis-0.2>
}

//object {Chair scale <5,5,5>}
 
       



