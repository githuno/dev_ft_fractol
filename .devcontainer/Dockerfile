FROM ubuntu:20.04
COPY .bashrc /root/

# タイムゾーンを設定（Asia/Tokyoに設定）
RUN ln -sf /usr/share/zoneinfo/Asia/Tokyo /etc/localtime

# ロケールを設定（日本語を使用する場合）
RUN apt-get update && apt-get install -y locales && rm -rf /var/lib/apt/lists/*
RUN sed -i -e 's/# ja_JP.UTF-8 UTF-8/ja_JP.UTF-8 UTF-8/' /etc/locale.gen
RUN dpkg-reconfigure --frontend=noninteractive locales
ENV LANG ja_JP.UTF-8  
ENV LC_ALL ja_JP.UTF-8

RUN apt update && apt install -y \
    gcc python3-pip\
    gdb \
    git vim nano sudo bash curl wget valgrind make dumb-init man-db\
    xorg libxext-dev zlib1g-dev libbsd-dev xdotool\
    openssh-server \
  && apt clean \
  && rm -rf /var/lib/apt/lists/* \
  && mkdir /var/run/sshd \
  # rootユーザーのパスワードをrootに設定
  && echo 'root:root' | chpasswd \
  # SSHのルートログインを許可 ※セキュリティ上のリスクあり
  && sed -i 's/#PermitRootLogin prohibit-password/PermitRootLogin yes/' /etc/ssh/sshd_config \
  # && /usr/sbin/sshd -d 待機し続けエラーになる
  && service ssh start

# norminette & formatter
RUN sudo python3 -m pip install --upgrade pip setuptools
RUN sudo python3 -m pip install norminette
RUN sudo python3 -m pip install c_formatter_42

WORKDIR /workspace

ENTRYPOINT [ "dumb-init", "/bin/bash" ]

# CMD /bin/sh -c "echo '準備完了' && sleep infinity"
