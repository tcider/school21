# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    mysql.sql                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcider <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/20 11:12:53 by tcider            #+#    #+#              #
#    Updated: 2021/01/20 14:54:19 by tcider           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UPDATE mysql.user SET plugin = 'mysql_native_password' WHERE user = 'root';
CREATE DATABASE wordpress;
GRANT ALL ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;
FLUSH PRIVILEGES;
