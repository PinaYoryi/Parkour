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
                    color="0, 0.3, 0.85"
                }
            }
        },
        {
            name="BotonV",
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
                    position="0.3,0.65",
                    size="240,100",
                    name="botonAtras",
                    properties="NormalImage,TaharezLook/ButtonMenu,HoverImage,TaharezLook/ButtonMenuHover,PushedImage,TaharezLook/ButtonMenuPushed",
                    type="CHANGE_SCENE",
                    showCursor="true",
                    continueBullet="true",
                    nextScene="menuprincipal.lua"
                }
     	    }
        },
        -- {
        --     name="BotonV",
        --     id=2,
        --     components={
        --         transform={
        --             position="0,0,0",
        --             rotation="0,0,0",
        --             scale="1,1,1",
        --             parent="-1"
        --         },
        --         button={
        --             text="Volver al menu",
        --             position="0.35,0.65",
        --             size="200,100",
        --             name="botonVolver",
        --             type="CHANGE_SCENE",
        --             showCursor="true",
        --             continueBullet="false",
        --             nextScene="menuprincipal.lua"
        --         }
     	--     }
        -- }
    }
}

function GetMapa ()
    return mapa
  end