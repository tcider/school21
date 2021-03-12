# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcider <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 11:50:39 by tcider            #+#    #+#              #
#    Updated: 2021/03/07 08:08:33 by tcider           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.12

WORKDIR /tmp

RUN apk update && \
	apk upgrade && \
	apk add gettext \
	telegraf --repository http://dl-2.alpinelinux.org/alpine/edge/community \
	&& rm -rf /var/cache/apk/* && mkdir -p /etc/telegraf

COPY telegraf.conf.tmp .
COPY telegraf_start.sh .

CMD sh telegraf_start.sh
