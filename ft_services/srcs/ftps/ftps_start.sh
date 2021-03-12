envsubst '${IP} ${FTPS_PORT_PAS}' < vsftpd.conf.tmp > vsftpd.conf
mv vsftpd.conf /etc/vsftpd/vsftpd.conf

mkdir -p /ftps/$FTPS_USER
adduser -h /ftps/$FTPS_USER -s /sbin/nologin -D $FTPS_USER
echo "$FTPS_USER:$FTPS_PASW" | chpasswd

/usr/sbin/vsftpd -opasv_address=$IP /etc/vsftpd/vsftpd.conf
