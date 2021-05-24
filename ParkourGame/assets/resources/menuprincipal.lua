local mapa = {
    ambient="0.1,0.1,0.1",
    gravity="0 -9.8 0",
    entities={
    {
     	name="Boton",
    	id=5,
     	components={
            button={
                text="Salir",
                position="0.5,0.5",
                size="100,100",
                name="botonSalir",
                type="EXIT",
                showCursor="true",
                nextScene=""
            }
            -- ,
            -- button={
            --     text="Empezar",
            --     position="0.5,15",
            --     size="100,100",
            --     name="botonEmpezar",
            --     type="CHANGE_SCENE",
            --     nextScene="level.lua"
            -- }   	
     	}
      }
    }
}

function GetMapa ()
    return mapa
  end