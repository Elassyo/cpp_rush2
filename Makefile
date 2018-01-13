##
## EPITECH PROJECT, 2018
## CPP Pool Rush 2
## File description:
## Makefile
##

#
# OUTPUT
#

NAME		=	santa

#
# SOURCES
#

MAINSRC		=	Santa.cpp

SRC		=	Object.cpp					\
			ObjectDB.cpp					\
			BoxStory/Box.cpp				\
			BoxStory/Wrap.cpp				\
			BoxStory/GiftPaper.cpp				\
			Elves/Hand.cpp					\
			Elves/IElf.cpp					\
			Elves/PapaXmasElf.cpp				\
			RandomFillers/ConveyorBeltRand.cpp		\
			RandomFillers/TableRand.cpp			\
			RollingCarpet/ConveyorBelt.cpp			\
			RollingCarpet/Table.cpp				\
			Toys/Teddy.cpp					\
			Toys/Toy.cpp					\
			Toys/LittlePony.cpp				\
			WarpMachine/WarpClient.cpp			\
			WarpMachine/WarpServer.cpp			\
			Xml/XmlToken.cpp				\
			Xml/XmlTextNode.cpp				\
			Xml/XmlParser.cpp				\
			Xml/XmlElementNode.cpp				\
			Xml/AXmlNode.cpp				\
			Xml/XmlException.cpp				\
			Xml/XmlLexer.cpp

#
# HEADERS
#

INC		=	Object.hpp					\
			ObjectDB.hpp					\
			BoxStory/Box.hpp				\
			BoxStory/GiftPaper.hpp				\
			BoxStory/Wrap.hpp				\
			Elves/Eyes.hpp					\
			Elves/Hand.hpp					\
			Elves/IElf.hpp					\
			Elves/PapaXmasElf.hpp				\
			RandomFillers/ConveyorBeltRand.hpp		\
			RandomFillers/TableRand.hpp			\
			RollingCarpet/ConveyorBelt.hpp			\
			RollingCarpet/IConveyorBelt.hpp			\
			RollingCarpet/ITable.hpp			\
			RollingCarpet/Table.hpp				\
			Toys/LittlePony.hpp				\
			Toys/Teddy.hpp					\
			Toys/Toy.hpp					\
			WarpMachine/WarpClient.hpp			\
			WarpMachine/WarpServer.hpp			\
			Xml/AXmlNode.hpp				\
			Xml/IXmlSerializable.hpp			\
			Xml/XmlElementNode.hpp				\
			Xml/XmlException.hpp				\
			Xml/XmlLexer.hpp				\
			Xml/XmlParser.hpp				\
			Xml/XmlTextNode.hpp				\
			Xml/XmlToken.hpp


#
# SYSTEM AND USER LIBS
#

LIB		=
USERLIB		=

#
# PATHS
#

SRCDIR		=	.
INCDIR		=	.
OBJDIR		=	obj
SUBDIRS		=	BoxStory Elves RandomFillers RollingCarpet Toys WarpMachine Xml
USERLIBDIR	=

#
# UNIT TESTS
#

TESTNAME	=

TESTSRC		=
TESTLIB		=

TESTSRCDIR 	=
TESTOBJDIR	=

#
# COMPILATION AND TOOLS
#

CC		=	g++

CPPFLAGS	=	-c -g -O2 -W -Wall -Wextra -I$(INCDIR)
LDFLAGS		=	$(addprefix -L$(USERLIBDIR)/lib, $(USERLIB)) $(addprefix -l, $(LIB) $(USERLIB))

TESTCPPFLAGS	=	-c -W -Wall -Wextra -ftest-coverage -fprofile-arcs -I$(INCDIR)
TESTLDFLAGS	=	--coverage $(addprefix -L$(USERLIBDIR)/lib, $(USERLIB)) $(addprefix -l, $(LIB) $(USERLIB) $(TESTLIB))

MAKE		=	make
MKDIR		=	mkdir
RM		=	rm -rf

#
# OBJECTS
#

OBJ		=	$(MAINSRC:.cpp=.o) $(SRC:.cpp=.o)
TESTOBJ		=	$(TESTSRC:.cpp=.o)

#
# TARGETS
#

all: $(NAME) $(TESTNAME)

$(NAME): $(addprefix $(OBJDIR)/, $(OBJ))
	$(CC) $^ $(LDFLAGS) -o $@

$(TESTNAME): $(addprefix $(TESTOBJDIR)/, $(OBJ) $(TESTOBJ))
	$(CC) $^ $(TESTLDFLAGS) -o $@

$(addprefix $(OBJDIR)/, $(OBJ)): $(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(addprefix $(INCDIR)/, $(INC)) | $(OBJDIR) $(addprefix $(OBJDIR)/,$(SUBDIRS))
	$(CC) $< $(CPPFLAGS) -o $@

$(addprefix $(TESTOBJDIR)/, $(OBJ)): $(TESTOBJDIR)/%.o: $(SRCDIR)/%.c $(addprefix $(INCDIR)/, $(INC)) | $(TESTOBJDIR) $(addprefix $(TESTOBJDIR)/,$(SUBDIRS))
	$(CC) $< $(TESTCPPFLAGS) -o $@

$(addprefix $(TESTOBJDIR)/, $(TESTOBJ)): $(TESTOBJDIR)/%.o: $(TESTSRCDIR)/%.c | $(TESTOBJDIR)
	$(CC) $< $(TESTCPPFLAGS) -o $@

$(OBJDIR) $(addprefix $(OBJDIR)/,$(SUBDIRS)) $(TESTOBJDIR) $(addprefix $(TESTOBJDIR)/,$(SUBDIRS)):
	$(MKDIR) $@

tests_run: $(TESTNAME)
	./$<

clean:
	$(RM) $(OBJDIR) $(TESTOBJDIR)

fclean: clean
	$(RM) $(NAME) $(TESTNAME)

re: fclean all

.PHONY:	all tests_run clean fclean re
