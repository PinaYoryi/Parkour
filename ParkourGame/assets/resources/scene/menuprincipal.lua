local mapa = {
    ambient="0.1,0.1,0.1",
    gravity="0 -9.8 0",
    entities={
        {
            name="Camera",
            id=1,
            components={
                transform={
                    position="0,0,0",
                    rotation="0,0,0",
                    scale="1,1,1",
                    parent="-1"
                },
                camera={
                    near="0.1",
                    far="1000",
                    autoaspect="true",
                    aspect="1.78",
                    fov="50",
                    proyection="1",
                    viewport="0,0,1,1",
                    color="0,0,0"
                }
            }
        },
        {
            name="BotonJ",
            id=2,
            components={
                transform={
                    position="0,0,0",
                    rotation="0,0,0",
                    scale="1,1,1",
                    parent="-1"
                },
                button={
                    text="",
                    position="0.43,0.40",
                    size="240,100",
                    name="botonJugar",
                    properties="NormalImage,TaharezLook/ButtonJugar,HoverImage,TaharezLook/ButtonJugarHover,PushedImage,TaharezLook/ButtonJugarPushed",
                    type="CHANGE_SCENE",
                    showCursor="true",
                    cursorImage="TaharezLook/MouseGeorgi",
                    continueBullet="true",
                    nextScene="level.lua"
                }
     	    }
        },
        {
            name="BotonO",
            id=3,
            components={
                transform={
                    position="0,0,0",
                    rotation="0,0,0",
                    scale="1,1,1",
                    parent="-1"
                },
                button={
                    text="",
                    position="0.43,0.57",
                    size="240,100",
                    name="botonOpciones",
                    properties="NormalImage,TaharezLook/ButtonControles,HoverImage,TaharezLook/ButtonControlesHover,PushedImage,TaharezLook/ButtonControlesPushed",
                    type="CHANGE_SCENE",
                    showCursor="true",
                    cursorImage="TaharezLook/MouseGeorgi",
                    continueBullet="true",
                    nextScene="menucontroles.lua"
                }
     	    }
        },
        {
            name="BotonS",
            id=4,
            components={
                transform={
                    position="0,0,0",
                    rotation="0,0,0",
                    scale="1,1,1",
                    parent="-1"
                },
                button={
                    text="",
                    position="0.43,0.75",
                    size="240,100",
                    name="botonSalir",
                    properties="NormalImage,TaharezLook/ButtonSalir,HoverImage,TaharezLook/ButtonSalirHover,PushedImage,TaharezLook/ButtonSalirPushed",
                    type="EXIT",
                    showCursor="true",
                    cursorImage="TaharezLook/MouseGeorgi",
                    continueBullet="false",
                    nextScene=""
                }
     	    }
        },
        {
            name="skyBox",
            id=4,
            components={
                transform={
                    position="0,0,0",
                    rotation="0,0,0",
                    scale="1,1,1",
                    parent="-1"
                },        
                skybox={
                    enable="true",
                    planenormal="Z",
                    planepos="20",
                    materialname="sky/space",
                    scale="1",
                    tiling="1",
                    drawfirst="true",
                    bow="10.0",
                    xsegments="10",
                    ysegments="10"
                }
            }
        },
        {
            name="Imagen",
            id=5,
            components={
                transform={
                    position="0,0,0",
                    rotation="0,0,0",
                    scale="1,1,1",
                    parent="-1"
                },
                image={
                    source="TaharezLook/Ogrevedad",
                    position="0.38,0.17",
                    size="450,130",
                    name="Titulo",
                    properties="BackgroundEnabled,false,FrameEnabled,false,Image,TaharezLook/Ogrevedad"
                }
            }
        },
        {
            name="musicBox",
            id=7,
            components={
                transform={
                    position="0,0,0",
                    rotation="0,0,0",
                    scale="1,1,1",
                    parent="-1"
                },
                musicplayer={
                },
                audiosource={
                    sound="TremLoadingloopl.wav",
                    volume="0.125",
                    velocity="0,0,0"
                }
            }
        }
    }
}

function GetMapa ()
    return mapa
  end