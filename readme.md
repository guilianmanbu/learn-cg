介绍：本项目是跟着《计算机图形学》一步一步操作的练习。


提示：
1. VC++6.0 在 Win10 上一定要以 windowXP 兼容模式运行。 在图标右键属性中设置。

问题与解决：
1. VC++6.0 的安装

VC++6.0 的安装使用了两个包才完成。一个解压包和一个正规安装包。

解压包解压即可运行，但编译后调试提示缺少库文件，说明环境不对，即使运行随包的.bat处理后仍然不行。
无奈，又下载了并运行了正规安装包，安装向导一路前行，眼看胜利曙光，可惜结束提示安装失败，无可操作的失败，
因为莫名奇妙。不过，这一向导过程倒是配置好了环境。我回头再试解压包的.exe，居然可以调试了。
也是柳暗花明又一村啊。所以，整个安装奇葩的用两个包完成了，由解压包提供vc本身，由安装包提供运行环境。