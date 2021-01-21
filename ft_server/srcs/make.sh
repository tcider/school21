# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    make.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcider <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/21 10:52:20 by tcider            #+#    #+#              #
#    Updated: 2021/01/21 17:09:22 by tcider           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cd ..
docker stop ft_server &> /dev/null
docker rm $(docker ps -qa) &> /dev/null
docker build -t ft_server .
docker run --name ft_server -p 80:80 -p 443:443 -d ft_server
docker exec -it ft_server bash
