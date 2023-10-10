nothing to do

做一款时间管理软件，哈哈

## 2023/8/16

完成了对话框的出现，感谢chatGPT

TODO:
- 明天完成任务的基本设置
- 添加任务到table中
- 尝试根据table的属性进行排序

## 2023/8/17

完成了时间的显示

接下来任务还需要添加:
- 剩余时间
- 当日截止时间
- 重要程度
- 链接资料 or 链接网页 or 参考

> 部分加入 table 中, 部分需要加入一个简述框中, 还需要进一步操作

一个问题是: **是否需要添加一个 task-list 来控制**

还需要添加日历显示等功能... 任务还挺多

## 2023/8/18

添加了文件的读写，现在 Table 可以得到保存.

有一个小问题就是，允许排序算法的话，那么势必要加入一个类似于 List 的管理抽象

而且简述，链接资料等，还需要进一步的操作和分析，需要有额外的 LineEdit 才能操作

所以最后还是得建立一个这样的抽象。

今天多的一个想法是：

- 在 Dialog 中加入日历来直接选择日期？
- 感觉直接手填倒也行，不过没有做鲁棒性检验，自己用倒是没有问题。

## 2023/8/23

添加debug的输出模块（感觉就是日志）

添加Task Class....

搞这么久，突然发现连删除某行都不会，现在需要重新继承一个 TableWidgets 然后添加鼠标点击操作，倒也不错。

绕了一大圈，还是没能找到直接加入这个自定义的操作的办法，明天继续问问GPT，看看能不能找到绕开的办法。

目前来看有两个操作，舍弃点击删除的操作（so stupid），直接构建一个子widget项目（so troublesome）。

## 2023/9/4

使用一个 layout 将他固定住了, 现在 ok 了

但是 select 的效果不太理想, 但目前也就这样讲究一下算了.


## 2023/9/6

选择一个 struct 来存储 task 的各种属性.

包括:
- 任务简称
- 任务发起时间
- 任务起始时间
- 任务终止时间
- 任务描述(这个还没想好是直接用 QString 存, 还是用文件的方式存储)
- 任务剩余时间(不好说, 不知是用天数, 还是)
- 任务序号(理论上默认是按照发起序, 可以理解成优先级, 但有点不一样)
- 任务优先级(初始化任务时复制)
- 任务状态(如待办、进行中、已完成, 中断, 放弃)
- 任务Tag, 这个暂时不知道怎么分类

敲定了任务处理的流程和api分配, 就差实现了.

## 2023/9/15

出现一个bug, 当 txt 中有实质性内容后, 启动失败


## 2023/10/10

回顾修改的地方, 开始查找问题所在

即`int TaskTableWidget::loadTask()`部分

原来是删除某些成员之后, data的索引没有修改, 导致越界...

ok: 现在添加功能完善! 接下来操作保存功能, 貌似会少一个

发现是少一个回车, 已解决.

删除功能添加完毕, 但是关闭自动保存功能貌似没有得到完美解决, 暂时不议.








