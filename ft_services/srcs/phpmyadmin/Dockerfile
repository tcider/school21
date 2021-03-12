# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcider <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/05 12:20:07 by tcider            #+#    #+#              #
#    Updated: 2021/03/06 11:39:48 by tcider           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.12

RUN apk update && \
	apk upgrade && \
	apk add nginx php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib \
	php7-curl php7-mbstring php7-json php7-session php7-iconv php7-xml gettext \
	&& rm -rf /var/cache/apk/* && \
	mkdir -p /run/nginx
RUN wget \
	https://www.phpmyadmin.net/downloads/phpMyAdmin-latest-all-languages.tar.gz \
	&& tar -xzvf phpMyAdmin-latest-all-languages.tar.gz && \
	mv phpMyAdmin*/ /usr/share/phpmyadmin/

WORKDIR	/tmp

COPY default.conf.tmp .
COPY config.inc.php.tmp .
COPY php_start.sh .

EXPOSE 5000

CMD sh php_start.sh
