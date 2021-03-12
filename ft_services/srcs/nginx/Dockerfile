# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcider <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/25 15:39:50 by tcider            #+#    #+#              #
#    Updated: 2021/03/10 19:15:24 by tcider           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.12

RUN apk update && \
	apk upgrade && \
	apk add nginx openssh openssl gettext &&  \
	rm -rf /var/cache/apk/*

WORKDIR	/tmp

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-out /etc/ssl/nginx.crt \
	-keyout /etc/ssl/nginx.key \
	-subj "/C=RU/ST=Tatarstan/L=Kazan/O=School21/CN=localhost" && \
	mkdir -p /run/nginx

COPY default.conf.tmp .
COPY index.html /var/www/localhost/htdocs/index.html
COPY nginx_start.sh .

EXPOSE 80 443 22

CMD sh nginx_start.sh
