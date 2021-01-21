# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcider <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/18 15:28:26 by tcider            #+#    #+#              #
#    Updated: 2021/01/21 17:39:41 by tcider           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

ENV AUTO_INDEX on

RUN mkdir /usr/src/ft_server
WORKDIR /usr/src/ft_server

RUN apt-get update && apt-get install -y \
	wget \
	nginx \
	php-fpm \
	default-mysql-server \
	php-mysql

# SSL configuration

RUN mkdir /etc/nginx/ssl && \
	openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-out /etc/ssl/certs/localhost.crt \
	-keyout /etc/ssl/private/localhost.key \
	-subj "/C=RU/ST=Tatarstan/L=Kazan/O=School21/CN=localhost"

# MySQL

COPY ./srcs/mysql/mysql.sql ./
RUN service mysql start && \
	mysql -u root < mysql.sql

# Nginx

COPY ./srcs/nginx/ft_server /etc/nginx/sites-available/
RUN sed -i "s/autoindex on/autoindex $AUTO_INDEX/g" \
	/etc/nginx/sites-available/ft_server && \
	rm -f /etc/nginx/sites-enabled/default && \
	ln -s /etc/nginx/sites-available/ft_server \
	/etc/nginx/sites-enabled/ft_server

# Wordpress

RUN wget https://wordpress.org/latest.tar.gz && \
	tar -xzvf latest.tar.gz -C /var/www && \
	chown -R www-data:www-data /var/www/wordpress
COPY ./srcs/wordpress/wp-config.php /var/www/wordpress/

# phpMyAdmin

RUN wget \
	https://www.phpmyadmin.net/downloads/phpMyAdmin-latest-all-languages.tar.gz \
	&& tar -xzvf phpMyAdmin-latest-all-languages.tar.gz && \
	mv phpMyAdmin*/ /var/www/wordpress/phpmyadmin/
COPY ./srcs/phpmyadmin/config.inc.php /var/www/wordpress/phpmyadmin/

EXPOSE 80 443

# Src for changing autoindex

COPY ./srcs/autoindex_off.sh ./
COPY ./srcs/autoindex_on.sh ./
RUN chmod +x autoindex_on.sh autoindex_off.sh
RUN mkdir /var/www/wordpress/test

COPY ./srcs/run_on_server.sh ./

CMD bash run_on_server.sh
