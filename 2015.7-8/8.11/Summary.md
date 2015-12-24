Activity
===
***

## ����
* Activity��Android�Ĵ����֮һ��Activity��Service����Content Provider�����ṩ�ߣ�BroadccastReceiver�㲥����������  

### ���ֻ���״̬
* Active/Running ��ʾ����Ļ��ǰ�ˣ�������ջ����ˣ��ɼ������û�����
* Paused  ʧȥ���㣬һ���µ�activity����ȫ����͸������������ջ��
* Stopped  ��Activity��ȫ���ɼ���������Activity���ǣ�����ϵͳ�ڴ���Ҫ���ڱ�ĵط���stopped��activity�ᱻkill
* Killed ҪôҪ���Activity������Ҫôǿ����ֹ����

### ��������
![Activity��������](http://b.hiphotos.baidu.com/baike/g%3D0%3Bw%3D268/sign=f146893ebe315c6053956ee4fa8cf925/1c950a7b02087bf41b6972c2f0d3572c11dfcf17.jpg "From AndroidHelpDocument")

***
## ��Android Studio�д���
### Android Studio�еĲ���
* manifests����Ϊxml���ݣ��Զ�����activity�ĸ�������
* java���ִ��Դ���룬����class�ȣ�����ֱ�����ɿ�ѡ��ģ��activity
* res���ְ���layout��layout�洢��Ӧ����activity��xml�ĵ�����ʾactivity�Ĳ��֣����Ҳ��Ӧdesign��text������ʾ��ʽ��design�����Ͽؼ���textֱ���޸�Դ����
* res���ְ���values������project�����õ�String��styles�Ⱦ��ڴ˶��壬��@string/hello_world����strings.xml�ж��壬<string name="hello_world">��Ҫ�������ַ���</string>������androidstudio�Զ����ɡ�

### Activity֮�䴫����Ϣ
#### ͨ����ť�������¼�
* �½�һ�����̣�ȫ��Ĭ��next��finish
* ��java�ļ����һ����½�new Activity -> Blank Activityģ�壬����ΪRemember���Զ�����activity_remember.xml��Remember��Class���Զ�extends ActionBarActivity����
* ��MainActivityԴ���룬��onCreate�����У���һ����ó��෽��`super.onCreate(savedInstanceState)`���ڶ���`setContentView(R.layout.activity_main)`��activity��setContentView��ʼִ�У������R.layout.activity_main��ΪR.layout.Remember�������ʱ��ֱ�Ӵ�Remember���activityִ��
* ��MainActivity��xml�µ�design��壬��קһ��Button�ؼ�����text�鿴���룬studio�Զ������˸�Button����ش��룬��Ĭ�ϵ�`android:id="@+id/button"`�޸�һ��id����`android:id="@+id/rembutton"`�����ͨ��rembutton��id����ȡ�����ť��������javascript�е�`getElementById()`
* ��MainActivity��onCreate�����м���  
 ```java
 
 findViewById(R.id.rembutton).setOnClickListener(new View.OnClickListener(){  
         @Override
         public void onClick(View v){
         ...
         }
  });
  
 ```
* ͨ����ť�����½���activity��Remember�����������onClick������д�����  
 ```java
 Intent i = new Intent(MainActivity.this,Remember.class);
 i.putExtra("message","not hello world");
 startActivity(i);
 ```
 ������Ĵ����У�i��һ���µĴ��ݵĶ���Intent��������һ��Activity��Ҳ��������һ��Service�������Է���һ���㲥Broadcasts��
 <table>
     <tr>
         <td>�������</td><td>��������</td>
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
 ͨ��i.putExtra(...)��i��������ݣ���һ������"message"�Ǵ���ֵ�����ƣ��ڶ���������ֵ��
* ��Remember��xml����ק�ؼ�Plain textView��Ĭ���ַ���ֵhelloworld���޸���id��Ĭ����textView���޸�Ϊtv����RememberԴ����
* ��Remember���м���`private TextView tv;`������һ������ָ��TextView�ؼ��ı�������OnCreate���������д���  
 ```java
 tv = (TextView)findViewById(R.id.tv);
 Intent i = getIntent();
 tv.setText(i.getStringExtra("message"));
 ```
 �Ƚ�tvָ��ոս�������������֮���ȡ���ݵ���Ϣ����Intent����getStringExtra�����õ�Intent�е�message�ַ�����
* ��������в������гɹ�

#### ���ݸ����ӵ�����
* ����Bundle���ݰ��������MainActivity�е�onClick�����м���  
```java

 Bundle b = new Bundle();  
 b.putString("data","test data");  
 b.putInt("age",2);  
 //Ҳ����b.putBundle(...);
 
 ```  
 ��Remember�м���`Bundle b = i.getExtras();`
 �޸�tv.setText(b.getStringExtra("data");
 
#### ������
* �½�һ��Class�ļ�������ΪUser
* ����`private String name;`��`private int age;`������getn,geta,setn,seta,�����Զ������ĸ��������ֶ�����`public User(){...}`���캯����
* �ഫ����Ҫ����ӿ�Percelable��Serializable��
* ��Serializable���ԣ�ֻҪ`public class User implements Serializable`���ɡ�  
  ��MainActivity��onClick�����У�`i.putExtra("user",new User("testname',2));`�����򴫵ݵĶ�����д��һ��User������Remember�н���ʱ��`User user = i.getSerializableExtra("user");`���ɣ�֮�����user.getName()�ȷ����ɻ�����ݡ�
* �Լ����͵����������֡��ַ���������ֱ��`intent.putExtra();`�������������ݱ���ʵ��Parcelable�ӿڡ���������
```java

    public interface Parcelable {
        //���������ӿ�
        public int describeContents();
        //д��ӿں��������
        public void writeToParcel(Parcel dest, int flags);
        //��ȡ�ӿڣ�Ŀ����Ҫ��Parcel�й���һ��ʵ����Parcelable�����ʵ��������Ϊʵ���������ﻹ�ǲ���֪�ģ�������Ҫ�õ�ģ��ķ�ʽ���̳�����ͨ��ģ���������
        //Ϊ���ܹ�ʵ��ģ������Ĵ��룬���ﶨ��CreatorǶ��ӿ�,�ں������ӿں����ֱ𷵻ص����Ͷ���̳���ʵ��
        public interface Creator<T> 
        {
           public T createFromParcel(Parcel source);
           public T[] newArray(int size);
        }
    }
```
�޸�User  
> ��`implements Serializable`�޸�Ϊ`implements Parcelable`  
AndroidStudio������ȱ����Ҫ�ķ�����ѡ����ӣ���class�¼���  
```java
    @Override public int describeContents(){
         return 0; 
    }
```
```java
    @Override public void writeToParcel(Parcel dest, int flags){
        ...//��dest.writeString(getName());dest.writeInt(getAge());   
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

* ��Remember���޸Ļ�ȡ��ķ�ʽΪ`i.getParcelableExtra()`

### Activity ������Ϣ
#### activityB����activityA��Intent�󷵻�text���޸�activityA��textView
* ��MainActivity�����˽����`private TextView textView`����onClick�е�`startActivity(i)`�޸�Ϊ`startActivityForResult(i,0)`������iΪ��������ݶ���0Ϊ�����루RequestCode����������������
* ��Remember������������ק�ؼ�����Ӵ���`<EditText...`��androidstudio���Զ���ȫ����קbutton���޸�����ʾ����Ϊ��Send Back����id��ʹ��Ĭ�ϼ��ɣ����޸ġ�
* ��Remember���������`private EditText ed`������onCreate�л�ȡ�����`ed = findViewByID(R.id.editText);`��֮����ť����¼�����������  
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

* ����Ĵ����У��½�һ����Ϣ����result��д���־Ϊmessage���ַ��������ݼ�Ϊ��activityB��������ַ�����setResult������һ������Ϊ���ص�Code���ڶ���Ϊ��Ϣ����Intent��finish()�����������̽���activityB������activityA��
* �ص�MainActivity����activityB�ոշ��ص���Ϣ����дһ����������������
```java

    protected void onActivityResult(int requestCode,int resultCode,Intent data){
        super.onActivityResult(requestCode,resultCode,data);
        textView.setText("Another activity is :"+data.getStringExtra("message"));
    }
```

* ������ͣ�onActivityResult���ڴ�������Ϣ������requestCodeΪ֮ǰstartActivityForResult�е������룬����ʱ��������resultCodeΪsetResult�еĵ�һ��������������activityB�з��ص�״̬����1����ɹ���0����ʧ�ܣ�2����...��������Ϊ���ص���Ϣ��

***
## Activity���ּ���ģʽ
### ����λ��
* ��manifests.xml�£��Ը���activity���Զ������������ļ�������һ��  
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

* ����Ĵ������½�һ��������ΪTest��BlankActivity�Զ����ɵ�activity���á����У�launchMode����ΪMainActivity�ļ���ģʽ����activity��ǩ֮���`<intent-filter></intent-filter>`���ݴ���app����ʱ�ӵ�ǰ��activity���أ���MainActivity��������һ��activity����������intent-filter�����ҽ�action����ΪMAIN��app���Ӹ�activity���ء�

### standard
* standardģʽ��Ĭ��ģʽ��ÿ�μ����µ�activity������֮ǰ����activity�Ƿ���ڣ����ᴴ����ʵ����������activity��ʹ��ͬһ��Taskջ����activity�п��Ե���`getTaskId()`������activity��TaskID��ͬ����hashCode��ͬ��

### singleTop
* singleTopģʽ��standard���Ὣintent���͵��µ�ʵ�������������singleTask��singleInstance����Ѿ�����һ��ʵ��������������µ�ʵ�������������singleTopģʽ��ջ���Ѿ�������Ҫ������ʵ������intent���͸�ջ������ǰ����ʵ���������½�ʵ����
* Ӧ�ã����ջ������ظ���ͬ��activity���⡣�����standardģʽ����acty1���ظ�����intent��acty1�����Ὠ�����acty1ʵ��������singleTop�У�ֻҪջ����acty1����ʼ�շ��͵���ǰacty��

### singleTask��singleInstance
* ���߶�ֻ����һ��ʵ������Intent����ʱ��ϵͳ����ջ���Ƿ����и�activity��ʵ��������Ѿ����ڣ���ֱ�Ӱ�intent���͸�����
* ����singleTask����˼��ֻ��һ��Taskջ��ÿ��acty��ջ�����ֻ��һ������singleInstance�򴴽�һ���µ�Taskջ����������µ�Taskջֻ��һ��actyʵ�����������������л�鿴�̼�λ�ã���򿪸ߵµ�ͼ�������home��Ȼ��򿪸ߵµ�ͼ���ᷢ�ֽ�����Ǹղ����������µġ�˵���ߵµ�ͼ��activity��һ��������taskջ�У���back����ʱ��ֻ�ǰ����taskջ�ƿ������Կ��������ŵ�task��

***
***
# Intent
***
## �����Ӧ��
### ��дActivity�е�����
* �½�һ��Default��MainActivity
* ��java��touchһ��class������ΪMyAty.class����Դ���룬extends Activity����Ҫ`import android.app.Activity;`��֮����onCreate������
* ��res�µ�layout�ļ����н���myaty��layoutSource��������ק�ؼ�������У�����MyAty��onCreate�а󶨲���`setContentView(R.layout.myaty);`
* ��manifests�µ�AndroidManifest.xml��ע��MyAty��`<activity android:name=".MyAty"/>`
* ��MainActivity�м��밴ť����Intent��MyAty��������Activity����

### Intent����ʽ����ʽ����
#### ��ʽIntent
* ��MainActivity����ťע������¼�ʱ��onClick(){...}����һ��`startActivity(new Intent(MainActivity.this,MyAtf.class));`�����ｫMyAtf.class�ڴ�������ȷ��Ϊ�������ݸ�Intent��

#### ��ʽIntent
* ��ֱ�Ӱ�Activity��Ϊ�������롣
* ������һ����������ʽIntent����manifests��ע��Activity��intent-filter����������:
```java

    <activity android:name=".MyAty" >
        <intent-filter>
            <category android:name="android.intent.category.DEFAULT";/>
            <action android:name="testddd"/>
        </intent-filter>
    </activity>    
```

* category���趨intentΪDEFAULTģʽ����intentָ��Activity��action��name��������Ϊ�ַ���������ͨ���ַ������ø�activity��
* ��ԭ����`new Intent(MainActivity.this,MyAty.class)`�޸�Ϊ`new Intent("testddd");`�ɹ�����app��
* ���׼������ʽΪio.github.forec.learnintent.intent.action. *** ������ *** Ϊ�Զ��塣ǰ���io.github.forecΪdomain��learnintentΪ��Ŀ���ơ�һ�㽫���Ϊһ����̬�����������ڶ�Ӧ������:
```java
    public class MyAty extends Activity{
        public static final String ACTION="io.github.forec.learnintent.intent.action.MyAty";
    ...
```
����������activity�п���ֱ�ӵ���MyAty.ACTION������ԭ���ĳ��ַ�����

* ���ƣ���AӦ���޷���ȡBӦ����activity�Ķ��壬������ͨ��.ACTION��ʽ����BӦ��

#### Intent-filter
* category������intent������
* action������intentִ�еĶ�����MAIN��VIEW...)
* data������Э���

