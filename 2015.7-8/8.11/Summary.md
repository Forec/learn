Activity
===
***

## 概念
* Activity是Android四大组件之一（Activity，Service服务，Content Provider内容提供者，BroadccastReceiver广播接收器）。  

### 四种基本状态
* Active/Running 显示在屏幕最前端，处理处于栈的最顶端，可见并与用户交互
* Paused  失去焦点，一个新的activity（非全屏或透明）被放置在栈顶
* Stopped  当Activity完全不可见（被其他Activity覆盖），当系统内存需要用在别的地方，stopped的activity会被kill
* Killed 要么要求该Activity结束，要么强行终止进程

### 生命周期
![Activity生命周期](http://b.hiphotos.baidu.com/baike/g%3D0%3Bw%3D268/sign=f146893ebe315c6053956ee4fa8cf925/1c950a7b02087bf41b6972c2f0d3572c11dfcf17.jpg "From AndroidHelpDocument")

***
## 在Android Studio中传递
### Android Studio中的布局
* manifests部分为xml数据，自动生成activity的各项属性
* java部分存放源代码，包括class等，可以直接生成可选的模板activity
* res部分包含layout，layout存储对应各个activity的xml文档，表示activity的布局，在右侧对应design和text两种显示格式，design可以拖控件，text直接修改源代码
* res部分包含values，整个project中引用的String，styles等均在此定义，如@string/hello_world，在strings.xml中定义，<string name="hello_world">需要命名的字符串</string>。均由androidstudio自动生成。

### Activity之间传递消息
#### 通过按钮生成新事件
* 新建一个工程，全部默认next到finish
* 在java文件夹右击，新建new Activity -> Blank Activity模板，命名为Remember，自动生成activity_remember.xml和Remember的Class（自动extends ActionBarActivity）。
* 打开MainActivity源代码，在onCreate方法中，第一句调用超类方法`super.onCreate(savedInstanceState)`，第二句`setContentView(R.layout.activity_main)`，activity从setContentView开始执行，如果将R.layout.activity_main改为R.layout.Remember，则测试时会直接从Remember这个activity执行
* 打开MainActivity的xml下的design面板，拖拽一个Button控件，打开text查看代码，studio自动生成了该Button的相关代码，将默认的`android:id="@+id/button"`修改一个id，如`android:id="@+id/rembutton"`，则可通过rembutton（id）获取这个按钮，类似于javascript中的`getElementById()`
* 在MainActivity的onCreate方法中加入  
 ```java
 
 findViewById(R.id.rembutton).setOnClickListener(new View.OnClickListener(){  
         @Override
         public void onClick(View v){
         ...
         }
  });
  
 ```
* 通过按钮激活新建的activity（Remember）。在上面的onClick方法中写入操作  
 ```java
 Intent i = new Intent(MainActivity.this,Remember.class);
 i.putExtra("message","not hello world");
 startActivity(i);
 ```
 在上面的代码中，i是一个新的传递的对象，Intent可以启动一个Activity，也可以启动一个Service，还可以发起一个广播Broadcasts。
 <table>
     <tr>
         <td>组件名称</td><td>方法名称</td>
     </tr>
     <tr>
         <td>Activity</td>
         <td>startActivity()</td>
     </tr>
     <tr>
         <td>Service</td><td>startService()</br>bindServier()</td>
     </tr>
     <tr>
         <td>Broadcasts</td><td>sendBroadcasts()</br>
         sendOrderedBroadcasts()</br>sendStickyBroadcasts</td>
     </tr>
 </table>
 通过i.putExtra(...)向i中添加数据，第一个参数"message"是传入值的名称，第二个参数是值。
* 打开Remember的xml，拖拽控件Plain textView，默认字符串值helloworld，修改其id，默认是textView，修改为tv。打开Remember源代码
* 在Remember类中加入`private TextView tv;`，增加一个可以指向TextView控件的变量。在OnCreate中增加下列代码  
 ```java
 tv = (TextView)findViewById(R.id.tv);
 Intent i = getIntent();
 tv.setText(i.getStringExtra("message"));
 ```
 先将tv指向刚刚建立的文字区域，之后获取传递的消息对象Intent，用getStringExtra方法得到Intent中的message字符串。
* 在虚拟机中测试运行成功

#### 传递更复杂的数据
* 传递Bundle数据包，上面的MainActivity中的onClick方法中加入  
```java

 Bundle b = new Bundle();  
 b.putString("data","test data");  
 b.putInt("age",2);  
 //也可以b.putBundle(...);
 
 ```  
 在Remember中加入`Bundle b = i.getExtras();`
 修改tv.setText(b.getStringExtra("data");
 
#### 传递类
* 新建一个Class文件，命名为User
* 加入`private String name;`，`private int age;`，键入getn,geta,setn,seta,代码自动生成四个方法。手动键入`public User(){...}`构造函数。
* 类传递需要满足接口Percelable或Serializable。
* 对Serializable而言，只要`public class User implements Serializable`即可。  
  在MainActivity的onClick方法中，`i.putExtra("user",new User("testname',2));`即可向传递的对象中写入一个User对象。在Remember中接收时，`User user = i.getSerializableExtra("user");`即可，之后调用user.getName()等方法可获得数据。
* 对简单类型的数据如数字、字符串，均可直接`intent.putExtra();`，复杂类型数据必须实现Parcelable接口。定义如下
```java

    public interface Parcelable {
        //内容描述接口
        public int describeContents();
        //写入接口函数，打包
        public void writeToParcel(Parcel dest, int flags);
        //读取接口，目的是要从Parcel中构造一个实现了Parcelable的类的实例处理。因为实现类在这里还是不可知的，所以需要用到模板的方式，继承类名通过模板参数传入
        //为了能够实现模板参数的传入，这里定义Creator嵌入接口,内含两个接口函数分别返回单个和多个继承类实例
        public interface Creator<T> 
        {
           public T createFromParcel(Parcel source);
           public T[] newArray(int size);
        }
    }
```
修改User  
> 将`implements Serializable`修改为`implements Parcelable`  
AndroidStudio会提醒缺少需要的方法，选择添加，在class下加入  
```java
    @Override public int describeContents(){
         return 0; 
    }
```
```java
    @Override public void writeToParcel(Parcel dest, int flags){
        ...//如dest.writeString(getName());dest.writeInt(getAge());   
    }
```
```java
    public static final Creator<User> CREATOR = new Creator<User>(){
        @Override
        public User createFromParcel(Parcel source){
            return new User(source);
        }
        @Override
        public User[] newArray(int size){
            return new User[size];
        }
    };
    public User(Parcel source){
        name = source.readString();
        age = source.readInt();
    }
```

* 在Remember中修改获取类的方式为`i.getParcelableExtra()`

### Activity 反馈消息
#### activityB接受activityA的Intent后返回text来修改activityA的textView
* 在MainActivity中添加私有域`private TextView textView`，将onClick中的`startActivity(i)`修改为`startActivityForResult(i,0)`，其中i为传输的内容对象，0为请求码（RequestCode），用于区别任务。
* 在Remember中添加输入框，拖拽控件或添加代码`<EditText...`，androidstudio将自动补全。拖拽button，修改其显示文字为“Send Back”，id均使用默认即可，可修改。
* 在Remember代码中添加`private EditText ed`，并在onCreate中获取其对象`ed = findViewByID(R.id.editText);`，之后向按钮添加事件，代码如下  
```java

    findViewById(R.id.button).setOnClickListener(new View.OnClickListener(){
        @Override
        public void onClick(View v){
            Intent result = new Intent();
            result.putExtra("message",ed.getText().toString());
            setResult(1,result);
            finish();
        }
    });
```

* 上面的代码中，新建一个消息对象result，写入标志为message的字符串，内容即为在activityB中输入的字符串。setResult函数第一个参数为返回的Code，第二个为消息对象Intent。finish()的作用是立刻结束activityB并返回activityA。
* 回到MainActivity处理activityB刚刚返回的消息。重写一个方法，代码如下
```java

    protected void onActivityResult(int requestCode,int resultCode,Intent data){
        super.onActivityResult(requestCode,resultCode,data);
        textView.setText("Another activity is :"+data.getStringExtra("message"));
    }
```

* 代码解释：onActivityResult用于处理返回消息。其中requestCode为之前startActivityForResult中的请求码，返回时区别任务。resultCode为setResult中的第一个参数，用于在activityB中返回的状态，如1代表成功，0代表失败，2代表...，最后参数为返回的消息。

***
## Activity四种加载模式
### 加载位置
* 在manifests.xml下，对各个activity均自动生成了配置文件。其中一例  
```java
    <activity
        android:name=".MainActivity"
        android:label="Test"
        android:launchMode="standard">
        <intent-filter>
            <action android:name="android.intent.action.MAIN"/>
            <category android:name="android.intent.category.LAUNCHER"/>
        </intent-filter>
    </activity>
```

* 上面的代码是新建一个工程名为Test的BlankActivity自动生成的activity配置。其中，launchMode属性为MainActivity的加载模式。在activity标签之间的`<intent-filter></intent-filter>`内容代表app启动时从当前的activity加载，即MainActivity。在任意一个activity配置中增加intent-filter，并且将action设置为MAIN，app将从该activity加载。

### standard
* standard模式是默认模式，每次加载新的activity，不管之前该类activity是否存在，都会创建新实例，但所有activity均使用同一个Task栈。在activity中可以调用`getTaskId()`，该类activity的TaskID相同，但hashCode不同。

### singleTop
* singleTop模式和standard都会将intent发送到新的实例（后面的两种singleTask和singleInstance如果已经存在一个实例，将不会产生新的实例）。但如果在singleTop模式下栈顶已经有了需要创建的实例，则将intent发送给栈顶（当前）的实例，不会新建实例。
* 应用：解决栈顶多个重复相同的activity问题。如果是standard模式，在acty1中重复发送intent给acty1，将会建立多个acty1实例，而在singleTop中，只要栈顶是acty1，就始终发送到当前acty。

### singleTask和singleInstance
* 二者都只创建一个实例。当Intent到来时，系统会检查栈中是否已有该activity的实例，如果已经存在，将直接把intent发送给它。
* 区别：singleTask顾名思义只有一个Task栈，每个acty在栈中最多只有一个。而singleInstance则创建一个新的Task栈，但是这个新的Task栈只有一个acty实例。举例：在美团中会查看商家位置，会打开高德地图，如果按home键然后打开高德地图，会发现界面会是刚才美团中留下的。说明高德地图的activity在一个独立的task栈中，当back回退时，只是把这个task栈移开，所以看到了美团的task。

***
***
# Intent
***
## 概念和应用
### 手写Activity中的例子
* 新建一个Default的MainActivity
* 在java下touch一个class，命名为MyAty.class，打开源代码，extends Activity，需要`import android.app.Activity;`，之后建立onCreate方法。
* 在res下的layout文件夹中建立myaty的layoutSource，随意拖拽控件到面板中，并在MyAty的onCreate中绑定布局`setContentView(R.layout.myaty);`
* 在manifests下的AndroidManifest.xml中注册MyAty。`<activity android:name=".MyAty"/>`
* 在MainActivity中加入按钮发送Intent给MyAty，操作如Activity例。

### Intent的显式和引式调用
#### 显式Intent
* 在MainActivity中向按钮注册监听事件时，onClick(){...}中有一句`startActivity(new Intent(MainActivity.this,MyAtf.class));`，这里将MyAtf.class在代码中明确作为参数传递给Intent。

#### 隐式Intent
* 不直接把Activity作为参数传入。
* 举例，一个常见的隐式Intent：在manifests中注册Activity的intent-filter。代码如下:
```java

    <activity android:name=".MyAty" >
        <intent-filter>
            <category android:name="android.intent.category.DEFAULT";/>
            <action android:name="testddd"/>
        </intent-filter>
    </activity>    
```

* category中设定intent为DEFAULT模式，即intent指向Activity；action的name随意设置为字符串，可以通过字符串调用该activity。
* 将原本的`new Intent(MainActivity.this,MyAty.class)`修改为`new Intent("testddd");`成功启动app。
* 其标准命名格式为io.github.forec.learnintent.intent.action. *** ，最后的 *** 为自定义。前面的io.github.forec为domain，learnintent为项目名称。一般将其存为一个静态常量，定义在对应的类中:
```java
    public class MyAty extends Activity{
        public static final String ACTION="io.github.forec.learnintent.intent.action.MyAty";
    ...
```
而在其他的activity中可以直接调用MyAty.ACTION来代替原本的长字符串。

* 优势：从A应用无法获取B应用中activity的定义，但可以通过.ACTION方式启动B应用

#### Intent-filter
* category：定义intent的属性
* action：定义intent执行的动作（MAIN，VIEW...)
* data：设置协议等

