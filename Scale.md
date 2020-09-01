## Scale

### 一、线性输入线性输出型

- continuous input domain to a continuous output range

1、scaleLinear（线性比例尺）

 Use a linear function (`y = m * x + b`) to interpolate across the domain and range.

```js
let linearScale = d3.scaleLinear()
  .domain([0, 10])
  .range(['yellow', 'red']);
```

2、scalePow（幂比例尺，Power—幂）

The power scale interpolates using a power (`y = m * x^k + b`) function.

- 指数 `k` 使用 `.exponent()`进行设定

```js
var powerScale = d3.scalePow()
  .exponent(0.5)
  .domain([0, 100])
  .range([0, 30]);
```

该比例尺是为了功能性的完整而设立的，实用性不如线性比例尺强。

3、scaleSqrt（scaleSqrt是scalePow比例尺k=0.5的特例）

```js
let sqrtScale = d3.scaleSqrt()
  .domain([0, 100])
  .range([0, 30]);
```

适用于用圆来表示数据大小的时候使用（当使用圆的大小来表征数据时，看面积比看半径的大小能更好的表征数据）

4、scaleLog（对数比例尺）

Log scales interpolate using a log function (`y = m * log(x) + b`) 

```js
var logScale = d3.scaleLog()
  .domain([10, 100000])
  .range([0, 600]);

logScale(10);     // returns 0
logScale(100);    // returns 150
logScale(1000);   // returns 300
logScale(100000); // returns 600
```

5、scaleTime（时间比例尺）

**Very** useful when dealing with time series data. It`s similar to scaleLiner.

时间比例尺将时间数组作为domain的输入，以range的范围作为插值区间进行插值。

```js
timeScale = d3.scaleTime()
  .domain([new Date(2016, 0, 1), new Date(2017, 0, 1)])
  .range([0, 700]);

timeScale(new Date(2016, 0, 1));   // returns 0
```

6、scaleSequential（顺序比例尺）

scaleSequential通常用于映射连续值到由预设（或自定义）插值器确定的输出范围。

插值器是一种函数，接受0到1之间的值作为输入，然后输出两个数字，颜色，字符串等之间的插值。

```js
let sequentialScale = d3.scaleSequential()
  .domain([0, 100])
  .interpolator(d3.interpolateRainbow);

sequentialScale(0);   // returns 'rgb(110, 64, 170)'
```

<img src="https://i.loli.net/2020/09/01/snexyqhSV6HMiJk.png" alt="image-20200831191829590" style="zoom: 67%;" />

同时，D3也提供了如下的许多插值器：（在 [d3-scale-chromatic](https://github.com/d3/d3-scale-chromatic) 可以查询）

<img src="https://i.loli.net/2020/09/01/Xxk5bBUydYmP9EC.png" alt="image-20200831193614918" style="zoom: 80%;" />

注意：输出范围由插值器决定，所以不必亲自去指定。

### Clamping 、夹紧

上述的所有比例尺默认都是允许在domain之外再输入值的，like this `linearScale(20)`

```js
let linearScale = d3.scaleLinear()
  .domain([0, 10])
  .range([0, 100]);

linearScale(20);  // returns 200
linearScale(-10); // returns -100
```

如果我们不想这样做，我们可以使用`.clamp()`功能来关闭外推法设置domain。

规则：`.clamp(true)`表示禁止使用域外插值，`.clamp(false)`表示可以使用默认方式域外插值。

```js
//Please focus on
linearScale.clamp(true);

linearScale(20);  // returns 100
linearScale(-10); // returns 0
```

### Nice、真奶思

此处的nice并非真的nice，看图知意：

使用nice之前：

```js
let data = [0.243, 0.584, 0.987, 0.153, 0.433];
//extent功能：使用自然排序返回指定数组的 最小值 和 最大值.
let extent = d3.extent(data);

let linearScale = d3.scaleLinear()
  .domain(extent)
  .range([0, 100]);
```

<img src="https://i.loli.net/2020/09/01/fuO5zVdI7oYT9cs.png" alt="image-20200831194959288" style="zoom:80%;" />

使用nice之后：

```js
let data = [0.243, 0.584, 0.987, 0.153, 0.433];
let extent = d3.extent(data);

let linearScale = d3.scaleLinear()
  .domain(extent)
  .range([0, 100]);
  .nice()
```

<img src="https://i.loli.net/2020/09/01/5P1H9MVbIDFSJKZ.png" alt="image-20200831195043505" style="zoom:80%;" />

Amazing！nice的功能就是使得坐标轴变得更加好看了，emm~

### 更多细节

1、通常`.domain`我们一般提供两个值，不过，我们可以提供多个值，使用比例函数将其分成多个段。

```js
let linearScale = d3
  .scaleLinear()
  .domain([-10, 0, 10])
  .range(["red", "#ddd", "blue"]);

let myData = [-10, -8, -6, -4, -2, 0, 2, 4, 6, 8, 10];
```

<img src="https://i.loli.net/2020/09/01/jwTnvN9LBdlVfQ7.png" alt="image-20200901171154128" style="zoom:80%;" />

首先，我们在domain里面使用了三个值，分成了两个段`[-10,0]` `[0,10]`；在range中也匹配了三个值，将其映射到两个段，`red=>灰色` `灰色=>blue`。值也是从，从两边向中间合拢，这样就制造了一个颜色分度盘。

通常使用正负值来标记段，只要dimain和range的长度相同，段的个数没有限制。

### 根据输出得到输入

`.invert()`方法允许我们根据输出得到输入的值，即根据range的值来计算出domain值。

```js
let linearScale = d3.scaleLinear()
  .domain([0, 10])
  .range([0, 100]);

linearScale.invert(50);   // returns 5
linearScale.invert(100);  // returns 10
```

<img src="https://i.loli.net/2020/09/01/lQFI1sTSarCJHt3.png" alt="image-20200901192518689" style="zoom:90%;" />

### 二、连续输入离散输出型

