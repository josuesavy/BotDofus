-- farm
GATHER = {1,38,254}

-- monsters
MIN_MONSTERS = 1
MAX_MONSTERS = 8
--FORBIDDEN_MONSTERS = {3270} -- Feu Vif
--MANDATORY_MONSTERS = {3272} -- Feu Furieux

-- global
AUTO_DELETE = {}
MAX_PODS = 90


function test()
    print("ui")
end

function move()
	return {
        -- Les déplacements, récoltes, combats

        { map = "154010884", changeMap="bottom", gather = true },
        --{ map = "154010885", changeMap="bottom" },

        --{ map = "154010883", fight=true, changeMap="right" },
        --{ map = "154010371", changeMap="left", fight=true },
        --{ map = "0,-3", changeMap="right", gather=true },
        --{ map = "153879299", changeMap="left", fight=true },
        --{ map = "153879811", changeMap="right", gather=true },
        --{ map = "153880323", changeMap="left", fight=true },
        --{ map = "153880835", changeMap="left", fight=true},
    }
end

function bank()
    return {
        -- Le retour en banque lorsque le personnage est en surpoids
    }
end

function phenix()
    return {
        -- La chemin vers le phenix si le personnage est mort
    }
end