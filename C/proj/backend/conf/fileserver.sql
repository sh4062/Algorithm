create database fileserver;
use fileserver;
DROP TABLE IF EXISTS `user`;
CREATE TABLE `user` (  
  `username` varchar(255) NOT NULL,
  `email` varchar(255) DEFAULT NULL,
  `password` varchar(255) NOT NULL,
  PRIMARY KEY (`username`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
INSERT INTO `user`(username, email, password) VALUES ('admin', 'admin@admin.com', '$5$elephant$6FB.OwMK4m3cPecgvEo7fWPJgBoAw6dwfn5Q1WiMQIA');
INSERT INTO `user`(username, email, password) VALUES ('admin2', 'admin2@admin.com', '$5$elephant$6FB.OwMK4m3cPecgvEo7fWPJgBoAw6dwfn5Q1WiMQIA');



DROP TABLE IF EXISTS `file`;
CREATE TABLE `file` (
  `count` int NOT NULL,
  -- `position` int NOT NULL,
  -- `type` varchar(10) NOT NULL,
  -- `dir` varchar(255) NOT NULL,
  -- `username` varchar(255) NOT NULL,
  -- `name` varchar(255) NOT NULL,
  `size` int NOT NULL,
  `localposition` varchar(255) NOT NULL,
  `md5` varchar(255)  NOT NULL,
  `ext` varchar(255) ,

  PRIMARY KEY (md5)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
INSERT INTO `file`(count,size,localposition,md5) VALUES (1,5,'../files/file1','test');
INSERT INTO `file`(count,size,localposition,md5) VALUES (1,55,'../files/file2','4aee3e28df37ea1af64bd636eca59dcb');
INSERT INTO `file`(count,size,localposition,md5) VALUES (1,55,'../files/dir1/file1','test2');
INSERT INTO `file`(count,size,localposition,md5) VALUES (1,0,'/','dir0');
INSERT INTO `file`(count,size,localposition,md5) VALUES (1,0,'/','dir1');        
INSERT INTO `file`(count,size,localposition,md5) VALUES (1,0,'/','admin2dir0');                      

DROP TABLE IF EXISTS `userfile`;
CREATE TABLE `userfile` (
  `proposition` int NOT NULL,
  `position` int NOT NULL,
  `type` varchar(10) NOT NULL,
  `dir` varchar(255) NOT NULL,
  `username` varchar(255) NOT NULL,
  `name` varchar(255) NOT NULL,
  -- `size` int NOT NULL,
  `absposition` varchar(255) NOT NULL,
  `md5` varchar(255)  NOT NULL,
  `ext` varchar(255) ,
  FOREIGN KEY (username) REFERENCES user(username),
  -- FOREIGN KEY (size) REFERENCES file(size),
  FOREIGN KEY (md5) REFERENCES file(md5),
  PRIMARY KEY (absposition)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
INSERT INTO `userfile`(proposition,position,type,dir,
username, name, absposition,md5) VALUES (0,0,'d','/','admin','admin','admin','dir0');

INSERT INTO `userfile`(proposition,position,type,dir,
username, name, absposition,md5) VALUES (0,1,'d','admin','admin','admin','admin/admin','dir1');

INSERT INTO `userfile`(proposition,position,type,dir,
username, name, absposition,md5) VALUES (0,0,'f','admin','admin','file1','admin/file1','test');

INSERT INTO `userfile`(proposition,position,type,dir,
username, name, absposition,md5) VALUES (0,0,'f','admin','admin','file2','admin/file2','4aee3e28df37ea1af64bd636eca59dcb');

INSERT INTO `userfile`(proposition,position,type,dir,
username, name, absposition,md5) VALUES (1,1,'f','admin','admin','file3','admin/admin/file3','test2');

INSERT INTO `userfile`(proposition,position,type,dir,
username, name, absposition,md5) VALUES (0,0,'d','/','admin2','admin2','admin2','admin2dir0');                  
