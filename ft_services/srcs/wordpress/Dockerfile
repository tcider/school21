# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcider <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/05 21:28:18 by tcider            #+#    #+#              #
#    Updated: 2021/03/10 21:56:16 by tcider           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.12

RUN apk update && \
	apk upgrade && \
	apk add mysql-client nginx php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib \
	php7-curl php7-mbstring php7-json php7-session php7-iconv php7-xml gettext \
	&& rm -rf /var/cache/apk/* && \
	mkdir -p /run/nginx

WORKDIR	/tmp

RUN wget https://wordpress.org/latest.tar.gz && \
	tar -xzvf latest.tar.gz -C /var/www

COPY wp-config.php.tmp .
COPY default.conf.tmp .
COPY wp_start.sh .
COPY wordpress.sql .

EXPOSE 5050

CMD sh wp_start.sh
