SERVERNAME= server
CLIENTNAME= client 
SRCSERVER = server.c
SRCCLIENT = client.c 
OBJSERVER = server.o 
OBJCLIENT = client.o
SERVERBONUS= server_bonus
CLIENTBONUS= client_bonus
SRCSERVERBNS = server_bonus.c
SRCCLIENTBNS = client_bonus.c
OBJSERVERBNS = server_bonus.o
OBJCLIENTBNS= client_bonus.o
FLAGS     = -Wall -Werror -Wextra

all: $(SERVERNAME) $(CLIENTNAME)

bonus: $(SERVERBONUS) $(CLIENTBONUS)

$(SERVERNAME): $(OBJSERVER)
	gcc $(OBJSERVER) -o $@

$(CLIENTNAME): $(OBJCLIENT)
	gcc $(OBJCLIENT) -o $@

$(SERVERBONUS): $(OBJSERVERBNS)
	gcc $(OBJSERVERBNS) -o $@

$(CLIENTBONUS): $(OBJCLIENTBNS)
	gcc $(OBJCLIENTBNS) -o $@

%.o: %.c 
	gcc $(FLAGS) $^ -c

clean: 
	rm -f $(OBJSERVER) $(OBJCLIENT) $(OBJSERVERBNS) $(OBJCLIENTBNS)

fclean: clean
	rm -f $(SERVERNAME) $(CLIENTNAME) $(SERVERBONUS) $(CLIENTBONUS) 

re: fclean all