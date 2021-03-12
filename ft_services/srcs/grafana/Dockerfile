# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcider <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 11:50:39 by tcider            #+#    #+#              #
#    Updated: 2021/03/11 16:22:40 by tcider           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.12

WORKDIR /tmp

RUN wget dl.grafana.com/oss/release/grafana-7.4.3.linux-amd64.tar.gz && \
	mkdir -p /grafana && \
	tar -C /grafana -xzvf grafana-7.4.3.linux-amd64.tar.gz --strip-components 1 && \
	rm -rf grafana-7.4.3.linux-amd64.tar.gz && \
	apk update && apk upgrade && apk add gettext \
	--repository=http://dl-cdn.alpinelinux.org/alpine/edge/main libc6-compat && \
	rm -rf /var/cache/apk/*

COPY defaults.ini.tmp .
COPY grafana_start.sh .
COPY datasource.yaml.tmp .
COPY home.json .
COPY dashboards/ ./dashboards/

EXPOSE 3000

CMD sh grafana_start.sh
