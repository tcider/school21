# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    autoindex_off.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcider <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/21 17:26:40 by tcider            #+#    #+#              #
#    Updated: 2021/01/21 17:29:20 by tcider           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

sed -i "s/autoindex on/autoindex off/g" \
	/etc/nginx/sites-available/ft_server
service nginx reload
