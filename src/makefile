SRCS=game.cpp main.cpp s_gameplay.hpp s_gameplay.cpp tex_manager.hpp tex_manager.cpp entities/misc/background.hpp entities/misc/background.cpp entities/misc/disco_lights.hpp entities/misc/disco_lights.cpp entities/base/AnimatedSprite.hpp entities/base/AnimatedSprite.cpp entities/base/Animation.hpp entities/base/Animation.cpp entities/player/player.hpp entities/player/player.cpp

CC=g++
CFLAGS= -std=c++11 -lsfml-graphics -lsfml-window -lsfml-system

OBJS=$(subst .cpp,.o,$(SRCS))

game:
	$(CC) $(CFLAGS) -o ../pyoro $(SRCS)

engine:
	$(CC) $(CFLAGS) main.cpp game.cpp game_state.cpp tex_manager.cpp entities/base/Animation.cpp entities/base/AnimatedSprite.cpp

states:
	$(CC) $(CFLAGS) s_gameplay.cpp

misc:
	$(CC) $(CFLAGS) entities/misc/background.cpp entities/misc/disco_lights.cpp

player: entities/player/player.cpp

# game:
#	 g++ $(SRCS) -o ../pyoro -std=c++11 -lsfml-graphics -lsfml-window -lsfml-system
