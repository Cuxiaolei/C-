#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;

typedef struct Thing
{
	char thing[100];


}Thing;

typedef struct BackLog
{
	int i;
	Thing thing[10];
}BackLog;

typedef struct Day
{
	int day;
	BackLog Log;
}Day;

typedef struct Month
{
	int month;
	int sumday;
	Day* day;
}Month;

typedef struct Year
{
	int year;
	Month* month;
	Year* next;
}Year;

typedef struct Link
{
	Year* head;
	Year* tail;
}Link;


//公历节日
const char* InitFestival(int month, int day)
{
	const char* festival = (char*)calloc(150, sizeof(char));
	festival = "非公立节日";
	if (month == 1)
	{
		if (day == 1)festival = "元旦";
		else if (day == 6)festival = "小寒";
		else if (day == 8)festival = "周恩来逝世纪念日";
		else if (day == 10)festival = "全国110宣传日 + 全国人民警察节日";
		else if (day == 14)festival = "日记情人节";
		else if (day == 20)festival = "大寒";
		else if (day == 26)festival = "国际海关日";
		else if (day == 27)festival = "国际大屠杀纪念日";
		else if (day == 28)festival = "国际麻风节";
	}

	else if (month == 2)
	{
		if (day == 2)festival = "世界湿地日";
		else if (day == 4)festival = "立春 + 世界抗癌日";
		else if (day == 7)festival = "国际声援南非日";
		else if (day == 10)festival = "国际气象节";
		else if (day == 13)festival = "世界无线电日";
		else if (day == 14)festival = "网络情人节";
		else if (day == 17)festival = "世界穿山甲日";
		else if (day == 19)festival = "雨水 + 邓小平逝世纪念日";
		else if (day == 20)festival = "世界社会公正日";
		else if (day == 21)festival = "国际母语日";
		else if (day == 24)festival = "第三世界青年日";
	}

	else if (month == 3)
	{
		if (day == 1)festival = "国际民防日 + 国际海豹日";
		else if (day == 3)festival = "世界野生动植物日 + 全国爱耳日";
		else if (day == 5)festival = "惊蛰 + 青年志愿者服务日 + 学雷锋纪念日";
		else if (day == 6)festival = "世界青光眼日";
		else if (day == 7)festival = "女生节";
		else if (day == 8)festival = "妇女节";
		else if (day == 9)festival = "保护母亲河日";
		else if (day == 12)festival = "植树节 + 孙中山逝世纪念日";
		else if (day == 14)festival = "世界肾脏日 + 世界反水坝日 + 白色情人节 + 圆周率日";
		else if (day == 15)festival = "消费者权益日";
		else if (day == 16)festival = "国际诚信节 + 手拉手情系贫困小伙伴全国统一行动日";
		else if (day == 17)festival = "中国国医节";
		else if (day == 18)festival = "科技人才活动日 + 全国爱肝日";
		else if (day == 20)festival = "春分 + 世界无肉日 + 国际幸福日";
		else if (day == 21)festival = "世界儿歌日 + 世界诗歌日 + 消除种族歧视国际日 + 世界森林日 + 世界睡眠日";
		else if (day == 22)festival = "世界水日";
		else if (day == 23)festival = "世界气象日";
		else if (day == 24)festival = "世界防治结核病日";
		else if (day == 25)festival = "全国中小学生安全教育日";
		else if (day == 27)festival = "世界戏剧日";
		else if (day == 29)festival = "中国黄花岗七十二烈士殉难纪念日";
		else if (day == 30)festival = "地球一小时日";
	}

	else if (month == 4)
	{
		if (day == 1)festival = "全国爱国卫生运动月(四月) + 国际爱鸟日 + 愚人节 + 税收宣传月(四月)";
		else if (day == 2)festival = "世界自闭症日 + 国际枕头大战日 + 国际儿童图书日";
		else if (day == 4)festival = "清明 + 国际地雷行动日";
		else if (day == 7)festival = "世界卫生日";
		else if (day == 8)festival = "国际珍稀动物保护日";
		else if (day == 9)festival = "国际护胃日";
		else if (day == 11)festival = "世界帕金森病日";
		else if (day == 12)festival = "世界航天日";
		else if (day == 13)festival = "泼水节";
		else if (day == 14)festival = "黑色情人节";
		else if (day == 15)festival = "全民国家安全教育日";
		else if (day == 16)festival = "世界嗓音日";
		else if (day == 17)festival = "世界铁哥们儿日 + 世界血友病日";
		else if (day == 18)festival = "国际古迹遗址日";
		else if (day == 19)festival = "谷雨";
		else if (day == 20)festival = "国际大麻日 + 中文语言日";
		else if (day == 21)festival = "全国企业家活动日";
		else if (day == 22)festival = "世界法律日 + 世界地球日";
		else if (day == 23)festival = "世界读书日";
		else if (day == 24)festival = "中国航天日 + 国际导盲犬日 + 亚非新闻工作者节 + 世界青年反对殖民主义日";
		else if (day == 25)festival = "儿童预防接种宣传日 + 世界防治疟疾日";
		else if (day == 26)festival = "全国疟疾日 + 世界知识产权日";
		else if (day == 27)festival = "世界平面设计日 + 世界兽医日";
		else if (day == 28)festival = "世界安全生产与健康日";
		else if (day == 29)festival = "化学战受害者纪念日 + 世界舞蹈日";
		else if (day == 30)festival = "国际不打小孩日 + 全国交通安全反思日";
	}

	else if (month == 5)
	{
		if (day == 1)festival = "劳动节";
		else if (day == 2)festival = "世界金枪鱼日";
		else if (day == 3)festival = "微商节 + 世界新闻自由日";
		else if (day == 4)festival = "五四青年节 + 科技传播日";
		else if (day == 5)festival = "立夏 + 国际助产士日";
		else if (day == 6)festival = "中国网络物流节";
		else if (day == 7)festival = "世界防治哮喘";
		else if (day == 8)festival = "世界卵巢癌日 + 世界微笑日 + 世界红十字日";
		else if (day == 10)festival = "中国品牌日";
		else if (day == 11)festival = "世界防治肥胖日";
		else if (day == 12)festival = "母亲节 + 护士节 + 救助贫困母亲日 + 全国防灾减灾日";
		else if (day == 14)festival = "玫瑰情人节";
		else if (day == 15)festival = "碘缺乏病防治日 + 国际家庭日";
		else if (day == 17)festival = "世界高血压日 + 世界电信日";
		else if (day == 18)festival = "国际博物馆日";
		else if (day == 19)festival = "世界家庭医生日 + 全国助残日 + 中国旅游日";
		else if (day == 20)festival = "小满 + 世界计量日 + 世界陌生人节 + 世界蜜蜂日 + 全国学生营养日 + 全国母乳喂养宣传日 + 网络情人节";
		else if (day == 21)festival = "世界文化发展日";
		else if (day == 22)festival = "国际生物多样性日";
		else if (day == 23)festival = "世界海龟日";
		else if (day == 25)festival = "国际失踪儿童日 + 世界预防中风日";
		else if (day == 26)festival = "世界向人体条件挑战日";
		else if (day == 28)festival = "全国爱发日";
		else if (day == 29)festival = "世界肠道健康日 + 国际维和人员日";
		else if (day == 30)festival = "全国科技工作者日 + 中国“五卅”运动纪念日";
		else if (day == 31)festival = "世界无烟日";
	}

	else if (month == 6)
	{
		if (day == 1)festival = "儿童节 + 世界牛奶日";
		else if (day == 3)festival = "世界自行车日";
		else if (day == 5)festival = "芒种 + 世界环境日";
		else if (day == 6)festival = "中国轮滑日 + 全国爱眼日";
		else if (day == 7)festival = "高考";
		else if (day == 8)festival = "文化和自然遗产日 + 世界海洋日";
		else if (day == 9)festival = "国际档案日 + 世界认可日";
		else if (day == 11)festival = "中国人口日";
		else if (day == 12)festival = "世界无童工日";
		else if (day == 14)festival = "亲亲情人节 + 世界献血者日";
		else if (day == 15)festival = "健康素食日";
		else if (day == 16)festival = "父亲节 + 国际非洲儿童日";
		else if (day == 17)festival = "防治荒漠化和干旱日";
		else if (day == 20)festival = "世界难民日";
		else if (day == 21)festival = "夏至 + 亚洲熄灯日 + 国际瑜伽日 + 世界渐冻人日";
		else if (day == 22)festival = "儿童慈善活动日";
		else if (day == 23)festival = "国际奥林匹克日 + 世界手球日";
		else if (day == 25)festival = "全国土地日";
		else if (day == 26)festival = "支援酷刑受害者日 + 国际禁毒日 + 国际宪章日";
		else if (day == 27)festival = "中小微企业日";
		else if (day == 30)festival = "世界青年联欢节";
	}

	else if (month == 7)
	{
		if (day == 1)festival = "建党节 + 香港回归纪念日";
		else if (day == 2)festival = "国际体育记者日";
		else if (day == 6)festival = "小暑 + 朱德逝世纪念日 + 国际合作节 + 国际接吻日";
		else if (day == 7)festival = "公共健康日 + 七七事变纪念日";
		else if (day == 8)festival = "世界过敏性疾病日";
		else if (day == 11)festival = "世界人口日 + 中国航海日";
		else if (day == 14)festival = "银色情人节";
		else if (day == 16)festival = "国际冰壶日";
		else if (day == 17)festival = "世界表情符号日 + 世界表情包日";
		else if (day == 18)festival = "曼德拉国际日";
		else if (day == 20)festival = "人类月球日";
		else if (day == 22)festival = "大暑";
		else if (day == 23)festival = "清洁工日";
		else if (day == 25)festival = "粤语日";
		else if (day == 26)festival = "世界语创立日";
		else if (day == 28)festival = "世界肝炎日";
		else if (day == 29)festival = "关公诞辰纪念日 + 世界爱虎日";
		else if (day == 30)festival = "国际友谊日";
	}

	else if (month == 8)
	{
		if (day == 1)festival = "建军节";
		else if (day == 3)festival = "男人节";
		else if (day == 5)festival = "恩格斯逝世纪念日";
		else if (day == 7)festival = "立秋";
		else if (day == 8)festival = "爸爸节 + 国际猫咪日 + 全民健身日";
		else if (day == 9)festival = "国际土著人日";
		else if (day == 11)festival = "全国肢残人活动日";
		else if (day == 12)festival = "世界大象日 + 国际青年节";
		else if (day == 13)festival = "国际左撇子日";
		else if (day == 14)festival = "绿色情人节";
		else if (day == 15)festival = "日本无条件投降日";
		else if (day == 18)festival = "中国人力资源日";
		else if (day == 19)festival = "中国医师节 + 世界人道主义日 + 世界摄影日";
		else if (day == 20)festival = "世界蚊子日";
		else if (day == 22)festival = "处暑";
		else if (day == 26)festival = "全国律师咨询日";
		else if (day == 29)festival = "全国测绘法宣传日";
	}

	else if (month == 9)
	{
		if (day == 1)festival = "全民健康生活方式日 + 全国中小学生开学日";
		else if (day == 3)festival = "天医节 + 抗日战争胜利纪念日";
		else if (day == 5)festival = "中华慈善日";
		else if (day == 7)festival = "白露";
		else if (day == 8)festival = "国际扫盲日 + 国际新闻工作者日";
		else if (day == 9)festival = "全国拒绝酒驾日 + 毛泽东逝世纪念日";
		else if (day == 10)festival = "世界预防自杀日 + 教师节";
		else if (day == 12)festival = "中国预防出生缺陷日";
		else if (day == 14)festival = "中国网民节 + 相片情人节 + 世界急救日 + 仝晓蕾的生日！！！！";
		else if (day == 15)festival = "全国科普日 + 国际民主日 + 豆腐文化节";
		else if (day == 16)festival = "国家网络安全宣传周 + 中国脑健康日 + 国际臭氧层保护日";
		else if (day == 17)festival = "中华老年痴呆日 + 世界骑行日";
		else if (day == 18)festival = "九一八事变纪念日";
		else if (day == 20)festival = "全国爱牙日 + 全国爱牙日 + 公民道德宣传日";
		else if (day == 21)festival = "世界清洁地球日 + 世界阿尔茨海默病日 + 全民国防教育日 + 国际和平日";
		else if (day == 22)festival = "秋分 + 国际聋人节 + 中国农民丰收节 + 世界无车日 + 国际熊猫节";
		else if (day == 26)festival = "世界避孕日";
		else if (day == 27)festival = "世界旅游日";
		else if (day == 28)festival = "孔子诞辰纪念日 + 世界狂犬病日";
		else if (day == 29)festival = "世界步行日 + 世界心脏日";
		else if (day == 30)festival = "烈士纪念日 + 国际翻译日";
	}

	else if (month == 10)
	{
		if (day == 1)festival = "国庆节 + 国际老年人日 + 世界音乐日 + 世界素食日";
		else if (day == 2)festival = "国际和平与民主自由斗争日 + 国际非暴力日";
		else if (day == 4)festival = "世界动物日";
		else if (day == 5)festival = "世界教师日";
		else if (day == 7)festival = "世界住房日 + 世界建筑日";
		else if (day == 8)festival = "寒露 + 全国高血压日";
		else if (day == 9)festival = "世界邮政日";
		else if (day == 10)festival = "世界精神卫生日 + 世界居室卫生日 + 世界视觉日 + 辛亥革命纪念日";
		else if (day == 11)festival = "世界镇痛日 + 国际女童日 + 国际出柜日";
		else if (day == 12)festival = "世界关节炎日";
		else if (day == 13)festival = "中国少年先锋队诞辰日 + 国际标准时间日 + 国际减轻自然灾害日 + 世界保健日";
		else if (day == 14)festival = "葡萄酒情人节 + 世界标准日";
		else if (day == 15)festival = "全球洗手日 + 国际盲人节";
		else if (day == 16)festival = "世界粮食日";
		else if (day == 17)festival = "扶贫日 + 世界消除贫困日";
		else if (day == 18)festival = "世界更年期关怀日";
		else if (day == 20)festival = "世界厨师日 + 世界统计日 + 世界骨质疏松日";
		else if (day == 22)festival = "国际口吃日 + 世界传统医药日";
		else if (day == 23)festival = "霜降 + 世界雪豹日";
		else if (day == 24)festival = "世界发展信息日 + 程序员节 + 联合国日";
		else if (day == 25)festival = "人类天花绝迹日 + 抗美援朝纪念日";
		else if (day == 26)festival = "环卫工人节";
		else if (day == 28)festival = "世界动画日 + 世界男性健康日";
		else if (day == 29)festival = "世界卒中日";
		else if (day == 31)festival = "世界城市日 + 世界勤俭日 + 万圣夜";
	}

	else if (month == 11)
	{
		if (day == 1)festival = "万圣节";
		else if (day == 5)festival = "世界海啸日";
		else if (day == 7)festival = "立冬 + 十月社会主义革命纪念日";
		else if (day == 8)festival = "记者节";
		else if (day == 9)festival = "全国消防日";
		else if (day == 10)festival = "世界青年节";
		else if (day == 11)festival = "国际科学与和平周 + 双十一购物狂欢节 + 光棍节 + 空军建军节";
		else if (day == 14)festival = "吉尼斯世界纪录日 + 电影情人节 + 世界糖尿病日";
		else if (day == 15)festival = "城市公共安全日";
		else if (day == 16)festival = "国际宽容日";
		else if (day == 17)festival = "国际肺癌日 + 世界早产日 + 国际大学生节";
		else if (day == 19)festival = "世界厕所日";
		else if (day == 20)festival = "世界慢性阻塞性肺病日 + 心梗救治日 + 世界儿童日";
		else if (day == 21)festival = "孙中山诞辰纪念日 + 世界问候日 + 世界电视日";
		else if (day == 22)festival = "小雪";
		else if (day == 25)festival = "国际素食日 + 消除对妇女的暴力日";
		else if (day == 28)festival = "感恩节";
		else if (day == 29)festival = "中国梦想日 + 国际声援巴勒斯坦人民日";
	}

	else if (month == 12)
	{
		if (day == 1)festival = "世界艾滋病日";
		else if (day == 2)festival = "全国交通安全日";
		else if (day == 3)festival = "世界残疾人日";
		else if (day == 4)festival = "全国法制宣传日";
		else if (day == 5)festival = "国际志愿人员日 + 世界土壤日 + 世界弱能人士日";
		else if (day == 6)festival = "大雪";
		else if (day == 7)festival = "国际民航日";
		else if (day == 8)festival = "沙县小吃节 + 国际儿童电视广播日";
		else if (day == 9)festival = "国际反腐败日 + 世界足球日 + 一二·九运动纪念日";
		else if (day == 10)festival = "世界人权日";
		else if (day == 11)festival = "国际山岳日";
		else if (day == 12)festival = "西安事变纪念日";
		else if (day == 13)festival = "国家公祭日";
		else if (day == 14)festival = "拥抱情人节";
		else if (day == 15)festival = "世界强化免疫日";
		else if (day == 18)festival = "国际移徙者日";
		else if (day == 20)festival = "澳门回归纪念日";
		else if (day == 21)festival = "冬至 + 国际篮球日";
		else if (day == 24)festival = "平安夜";
		else if (day == 25)festival = "圣诞节";
		else if (day == 26)festival = "毛泽东诞辰纪念日";
	}
	return festival;
}

//每个月的天数初始化
Day* InitDay(int month, int sumday)
{
	Day* p = (Day*)calloc(sumday, sizeof(Day));
	for (int i = 0; i < sumday; i++)
	{
		p[i].day = i + 1;
		p[i].Log.i = 0;
	}
	return p;
}

//每年的月数初始化
Month* InitMonth(int year)
{
	Month* p = (Month*)calloc(12, sizeof(Month));
	int day[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	for (int i = 0; i < 12; i++)
	{
		if ((i + 1) == 2)
		{
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			{
				day[1] = 29;
			}
		}
		p[i].month = i + 1;
		p[i].day = InitDay(p[i].month, day[i]);
		p[i].sumday = day[i];
	}
	return p;
}

//1940-2040链表初始化
void Init(Link* p)
{
	p->head = NULL;
	p->tail = NULL;
	for (int i = 1940; i <= 2040; i++)
	{
		Year* cur = (Year*)calloc(1, sizeof(Year));	//开一年空间
		cur->year = i;
		cur->month = InitMonth(i);
		cur->next = NULL;
		if (p->head == NULL)
		{
			p->head = cur;
		}
		else
		{
			p->tail->next = cur;
		}
		p->tail = cur;
	}
}

//计算某一年的第一天为星期几
int TheYearFirstDay(int year)
{
	int sum = 0;
	//1934年第一天为星期一，故从1905年算起
	for (int i = 1934; i < year; i++)
	{
		//闰年366天
		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
		{
			sum += 366;
		}
		else
		{
			sum += 365;
		}
	}
	return (sum % 7) + 1;
}

//打印某月的表头
void ShowMonthHead(Year* p, int month)
{
	cout << setw(2) << right << p->month[month].month << "月" << " ";
	cout << setw(4) << left << "Mon";
	cout << setw(4) << left << "Tue";
	cout << setw(4) << left << "Wed";
	cout << setw(4) << left << "Thu";
	cout << setw(4) << left << "Fri";
	cout << setw(4) << left << "Sat";
	cout << setw(4) << left << "Sun";
}

//打印某个月的日历（被调用）
void ShowMonthDate1(Year* p, int month, int firstday)
{
	//如果第一天是星期日，那么传过来的firstday 是 0
	if (firstday == 0)
	{
		cout << "                        ";
	}
	cout << "     ";
	//在每个月的第一天之前打印空格
	for (int t = 0; t < firstday - 1; t++)
	{
		cout << "    ";
	}
	//打印这个月的每一天
	for (int i = 0; i < p->month[month].sumday; i++)
	{
		cout << setw(4) << left << p->month[month].day[i].day;
		firstday++;

		//每次打印到星期日就换行
		if ((firstday - 1) % 7 == 0)
		{
			cout << endl;
			cout << "     ";
		}
	}
	cout << endl;
}

//打印某一年的年历
void ShowYear(Link* link)
{
	Year* p = link->head;
	int year;
	cout << "想要查看那一年的日历：";
	cin >> year;
	//计算这一年第一天星期几
	int firstday = TheYearFirstDay(year);
	//找到这一年的节点
	while (p != NULL && p->year != year)
	{
		p = p->next;
	}
	int i, j, k;
	if (p == NULL)
	{
		cout << "输入错误" << endl;
		return;
	}

	//控制输出格式
	cout << "===============================================" << year << "年历==================================================" << endl;
	for (i = 0, j = 1, k = 2; i < 12; i += 3, j += 3, k += 3)
	{
		cout << "|";
		ShowMonthHead(p, i);
		cout << "  ";
		ShowMonthHead(p, j);
		cout << "  ";
		ShowMonthHead(p, k);
		cout << "|";
		cout << endl;
		//记录每个月第一天是星期几
		int firstday1 = firstday;
		int firstday2 = (firstday + p->month[i].sumday) % 7;
		int firstday3 = (firstday + p->month[i].sumday + p->month[j].sumday) % 7;

		int t1 = 0;
		int t2 = 0;
		int t3 = 0;

		int f1 = 0;
		int f2 = 0;
		int f3 = 0;
		while (t1 < p->month[i].sumday || t2 < p->month[j].sumday || t3 < p->month[k].sumday)
		{
			//1、4、7、10月
			//在每个月的第一天之前打印空格
			cout << "|     ";
			//每个月开始时可能是星期日，传过来的firstday为0
			if (firstday1 == 0)
				cout << "                        ";
			for (int t = 0; t < firstday1 - 1; t++)
				cout << "    ";

			for (int n1 = t1; n1 < p->month[i].sumday; n1++)
			{
				cout << setw(4) << left << p->month[i].day[n1].day;
				firstday1 += 1;///2 3 4 5 6 7 8
				t1++;			//1 2 3 4 5 6 7
				if ((firstday1 - 1) % 7 == 0)
				{
					firstday1 = firstday1 % 7;
					break;
				}
			}
			//如果在每三个月最后一行要空出每个月最后一行的空格
			if (t1 == p->month[i].sumday)
			{
				if (firstday1 == 1)
				{
					if (f1 == 1)
						cout << "                            ";
				}
				//每次firstday1为 1 ，最后如果输出3天，则firstday1为4，需要补7-（4-1）次空格
				if (firstday1 != 1)
				{
					for (int s = 0; s < (7 - firstday1 + 1); s++)
					{
						cout << "    ";
					}
				}
				f1 = 1;
			}

			//2、5、8、11月
			cout << "  ";
			cout << "     ";
			if (firstday2 == 0)
				cout << "                        ";
			for (int t = 0; t < firstday2 - 1; t++)
				cout << "    ";
			for (int n2 = t2; n2 < p->month[j].sumday; n2++)
			{
				cout << setw(4) << left << p->month[j].day[n2].day;
				firstday2 += 1;
				t2++;
				if ((firstday2 - 1) % 7 == 0)
				{
					firstday2 = firstday2 % 7;
					break;
				}
			}
			//如果在每三个月最后一行要空出每个月最后一行的空格
			if (t2 == p->month[j].sumday)
			{
				if (firstday2 == 1)
				{
					if (f2 == 1)
						cout << "                            ";//七天的四个空格
				}
				if (firstday2 != 1)
				{
					for (int s = 0; s < (7 - firstday2 + 1); s++)
					{
						cout << "    ";
					}
				}
				//在倒数第二行输出完之后标记一下
				f2 = 1;
			}


			//3、6、9、12月
			cout << "  ";
			cout << "     ";
			if (firstday3 == 0)
				cout << "                        ";
			for (int t = 0; t < firstday3 - 1; t++)
				cout << "    ";
			for (int n3 = t3; n3 < p->month[k].sumday; n3++)
			{
				cout << setw(4) << left << p->month[i].day[n3].day;
				firstday3 += 1;
				t3++;
				if ((firstday3 - 1) % 7 == 0)
				{
					firstday3 = firstday3 % 7;
					break;
				}
			}
			//如果在每三个月最后一行要空出每个月最后一行的空格
			if (t3 == p->month[k].sumday)
			{
				if (firstday3 == 1)
				{
					if (f3 == 1)
						cout << "                            ";//七天的四个空格
				}
				if (firstday3 != 1)
				{
					for (int s = 0; s < (7 - firstday3 + 1); s++)
					{
						cout << "    ";
					}
				}
				//在倒数第二行输出完之后标记一下
				f3 = 1;
			}

			cout << "|";
			cout << endl;
		}
		//每三个月重置一下三个月的第一天星期几
		firstday = (firstday + p->month[i].sumday + p->month[j].sumday + p->month[k].sumday) % 7;
	}
	cout << "=========================================================================================================" << endl;
}


//打印某个月的日历
void ShowMonthDate(Link* link)
{
	Year* p = link->head;
	int year, month;
	cout << "请输入要输出月历的年月：";
	cin >> year >> month;
	if (month > 12 || month < 1)
	{
		cout << "你家有" << month << "月啊！！！";
		return;
	}
	while (p->next != NULL && p->year != year)
	{
		p = p->next;
	}

	int firstday = TheYearFirstDay(year);

	if (p->year == year)
	{

		for (int i = 0; i < month - 1; i++)
		{
			firstday = (firstday + p->month[i].sumday) % 7;
		}
		ShowMonthHead(p, month - 1);
		cout << endl;
		ShowMonthDate1(p, month - 1, firstday);
	}
	else
	{
		cout << "你输入了不正确的年数" << endl;
	}
}

//查询某天的数据
void FindSomeday(Link* link)
{
	Year* p = link->head;
	cout << "请输入需要查询的年月日：";
	int year, month, day;
	cin >> year >> month >> day;

	//定位到当前节点
	if (month > 12 || month < 1)
	{
		cout << "你家有" << month << "月啊！！！";
		return;
	}
	while (p->next != NULL && p->year != year)
	{
		p = p->next;
	}
	if (day > p->month[month - 1].sumday || day < 0)
	{
		cout << "你家" << year << "年" << month << "月有" << day << "天啊！！！！" << endl;
		return;
	}




	//当前时间
	int i;
	time_t time0;
	time0 = time(NULL);
	struct tm* systemtime = localtime(&time0);
	int curyear = systemtime->tm_year + 1900;
	int curmonth = systemtime->tm_mon + 1;
	int curday = systemtime->tm_mday;

	int sum = 0;

	if (year < curyear)
	{
		for (i = year; i < curyear; i++)
		{
			if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) sum += 366;	//闰年记366天
			else sum += 365;												//否则记365天
		}

		if (month < curmonth)
		{
			//循环加上相差月数所对应的天数
			for (i = month; i < curmonth; i++)sum += p->month[i - 1].sumday;

			//计算相差的天数
			if (day < curday)sum += (curday - day);
			else if (day == curday) sum = sum;
			else if (day > curday)sum = sum - (day - curday);
		}

		else if (month == curmonth)
		{
			//计算相差的天数
			if (day < curday) sum += (curday - day);
			else if (day == curday) sum = sum;
			else if (day > curday)sum = sum - (day - curday);
		}

		else if (month > curmonth)
		{
			//循环减去相差月数所对应的天数(减去所要查询那一年的当月天数)
			for (i = curmonth; i < month; i++)sum -= p->month[i - 1].sumday;

			//计算相差的天数
			if (day < curday)sum += (curday - day);
			else if (day == curday) sum = sum;
			else if (day > curday)sum = sum - (day - curday);
		}
	}

	if (year == curyear)
	{
		if (month < curmonth)
		{
			//循环加上相差月数所对应的天数
			for (i = month; i < curmonth; i++)sum += p->month[i - 1].sumday;

			//计算相差的天数
			if (day < curday)sum += (curday - day);
			else if (day == curday) sum = sum;
			else if (day > curday)sum = sum - (day - curday);
		}

		else if (month == curmonth)
		{
			//计算相差的天数
			if (day < curday)sum += (curday - day);
			else if (day == curday) sum = sum;
			else if (day > curday)sum = sum - (day - curday);
		}

		else if (month > curmonth)
		{
			//循环减去相差月数所对应的天数(减去所要查询那一年的当月天数)
			for (i = curmonth; i < month; i++)sum -= p->month[i - 1].sumday;

			//计算相差的天数
			if (day < curday)sum += (curday - day);
			else if (day == curday) sum = sum;
			else if (day > curday)sum = sum - (day - curday);
		}
	}

	if (year > curyear)
	{
		for (i = curyear; i < year; i++)
		{
			if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) sum -= 366;	//闰年记366天
			else sum -= 365;												//否则记365天
		}

		if (month < curmonth)
		{
			//循环加上相差月数所对应的天数
			for (i = month; i < curmonth; i++)sum += p->month[i - 1].sumday;

			//计算相差的天数
			if (day < curday)sum += (curday - day);
			else if (day == curday) sum = sum;
			else if (day > curday)sum = sum - (day - curday);
		}

		else if (month == curmonth)
		{
			//计算相差的天数
			if (day < curday)sum += (curday - day);
			else if (day == curday) sum = sum;
			else if (day > curday)sum = sum - (day - curday);
		}

		else if (month > curmonth)
		{
			//循环减去相差月数所对应的天数(减去所要查询那一年的当月天数)
			for (i = curmonth; i < month; i++)sum -= p->month[i - 1].sumday;

			//计算相差的天数
			if (day < curday)sum += (curday - day);
			else if (day == curday) sum = sum;
			else if (day > curday)sum = sum - (day - curday);
		}
	}

	if (sum >= 0)
	{
		cout << "距今天已经过去" << sum << "天了" << endl;
	}
	else
	{
		cout << "距今还有" << -sum << "天" << endl;
	}

	//当前星期几
	int firstday = TheYearFirstDay(year) - 1;
	for (int i = 0; i < month - 1; i++)
	{
		firstday = firstday + p->month[i].sumday;
	}

	firstday += day;
	firstday = firstday % 7;
	if (firstday == 1)cout << "星期一";
	else if (firstday == 2)cout << "星期二";
	else if (firstday == 3)cout << "星期三";
	else if (firstday == 4)cout << "星期四";
	else if (firstday == 5)cout << "星期五";
	else if (firstday == 6)cout << "星期六";
	else if (firstday == 0)cout << "星期日";
	cout << endl;
	const char* festival = InitFestival(month, day);
	cout << festival << endl;
}

//增加待办
void AddBackLog(Link* link)
{
	Year* p = link->head;
	cout << "请输入要增加待办的日子:";
	int year, month, day;
	cin >> year >> month >> day;
	//定位到当前节点
	if (month > 12 || month < 1)
	{
		cout << "你家有" << month << "月啊！！！";
		return;
	}
	while (p->next != NULL && p->year != year)
	{
		p = p->next;
	}
	if (day > p->month[month - 1].sumday || day < 0)
	{
		cout << "你家" << year << "年" << month << "月有" << day << "天啊！！！！" << endl;
		return;
	}
	cout << "请输入待办的事件（输入0退出）:";
	int t = 0;
	int i = p->month[month - 1].day[day - 1].Log.i;
	while (1)
	{
		cin >> p->month[month - 1].day[day - 1].Log.thing[i].thing;
		if (strcmp(p->month[month - 1].day[day - 1].Log.thing[i].thing, "0") == 0)
		{
			if (t == 1)
			{
				cout << "添加成功!!" << endl;
				return;
			}
			else
			{
				cout << "已退出";
				return;
			}
		}
		p->month[month - 1].day[day - 1].Log.i++;
		t = 1;
		i++;
	}
}

//删除待办
void DeleBackLog(Link* link)
{
	Year* p = link->head;
	cout << "请输入要删除待办的日子:";
	int year, month, day;
	cin >> year >> month >> day;
	//定位到当前节点
	if (month > 12 || month < 1)
	{
		cout << "你家有" << month << "月啊！！！";
		return;
	}
	while (p->next != NULL && p->year != year)
	{
		p = p->next;
	}
	if (day > p->month[month - 1].sumday || day < 0)
	{
		cout << "你家" << year << "年" << month << "月有" << day << "天啊！！！！" << endl;
		return;
	}

	p->month[month - 1].day[day - 1].Log.i = 0;
	cout << "删除成功！！" << endl;
}

//修改待办
void MondifyBackLog(Link* link)
{
	Year* p = link->head;
	cout << "请输入要修改待办的日子:";
	int year, month, day;
	cin >> year >> month >> day;
	//定位到当前节点
	if (month > 12 || month < 1)
	{
		cout << "你家有" << month << "月啊！！！";
		return;
	}
	while (p->next != NULL && p->year != year)
	{
		p = p->next;
	}
	if (day > p->month[month - 1].sumday || day < 0)
	{
		cout << "你家" << year << "年" << month << "月有" << day << "天啊！！！！" << endl;
		return;
	}

	p->month[month - 1].day[day - 1].Log.i = 0;
	cout << "请修改该天的待办事件（输入0退出）:";
	int t = 0;
	int i = 0;
	while (1)
	{
		cin >> p->month[month - 1].day[day - 1].Log.thing[i].thing;
		if (strcmp(p->month[month - 1].day[day - 1].Log.thing[i].thing, "0") == 0)
		{
			if (t == 1)
			{
				cout << "添加成功!!" << endl;
				return;
			}
			else
			{
				cout << "已退出";
				return;
			}
		}
		p->month[month - 1].day[day - 1].Log.i++;
		t = 1;
		i++;
	}
	cout << "修改成功！！" << endl;
}

//查询待办
void FindBackLog(Link* link)
{
	Year* p = link->head;
	char input;
	cout << "请输入要查询的方式（1.查询某天待办 2.查询某个月的待办：）:";
	cin >> input;
	if (input == '1')
	{
		//cout << "请输入需要查询的年月日:";
		int year, month, day;
		cin >> year >> month >> day;

		//定位到当前节点
		if (month > 12 || month < 1)
		{
			cout << "你家有" << month << "月啊！！！";
			return;
		}
		while (p->next != NULL && p->year != year)
		{
			p = p->next;
		}
		if (day > p->month[month - 1].sumday || day < 0)
		{
			cout << "你家" << year << "年" << month << "月有" << day << "天啊！！！！" << endl;
			return;
		}

		//查询
		if (p->month[month - 1].day[day - 1].Log.i == 0)
		{
			cout << "无待办" << endl;
		}
		else
		{
			for (int i = 0; i < p->month[month - 1].day[day - 1].Log.i; i++)
			{
				cout << i + 1 << ".";
				cout << p->month[month - 1].day[day - 1].Log.thing[i].thing << endl;
			}
		}
		cout << endl;
	}
	else if (input == '2')
	{
		cout << "请输入需要查询的年月：";
		int year, month;
		cin >> year >> month;

		//定位到当前节点
		if (month > 12 || month < 1)
		{
			cout << "你家有" << month << "月啊！！！";
			return;
		}
		while (p->next != NULL && p->year != year)
		{
			p = p->next;
		}
		for (int i = 0; i < p->month[month - 1].sumday; i++)
		{
			cout << "第" << setw(2) << i + 1 << "天" << "： ";
			if (p->month[month - 1].day[i].Log.i == 0)
			{
				cout << "无待办" << endl;
			}
			else
			{
				for (int j = 0; j < p->month[month - 1].day[i].Log.i; j++)
				{
					cout << j + 1 << ".";
					cout << p->month[month - 1].day[i].Log.thing[j].thing << "     ";
				}
				cout << endl;
			}
		}
	}
	else
	{
		cout << "输入不合法" << endl;
		return;
	}
}

//保存
void Save(Link* link)
{
	Year* p = link->head;
	FILE* pfwrite = fopen("日历.txt", "wb");
	if (pfwrite == NULL)
	{
		perror("Save");
		return;
	}
	while (p != NULL)
	{
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < p->month[i].sumday; j++)
			{
				fwrite(&p->month[i].day[j].Log, sizeof(BackLog), 1, pfwrite);
			}
		}
		p = p->next;
	}
	cout << "保存成功" << endl;
	fclose(pfwrite);
	pfwrite = NULL;
}

//加载
void Load(Link* link)
{
	Year* p = link->head;
	FILE* pfread = fopen("日历.txt", "rb");
	if (pfread == NULL)
	{
		perror("Load");
		return;
	}
	while (p != NULL)
	{
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < p->month[i].sumday; j++)
			{
				fread(&p->month[i].day[j].Log, sizeof(BackLog), 1, pfread);
			}
		}
		p = p->next;
	}
	fclose(pfread);
	pfread = NULL;
}

//清屏
void Clean()
{
	cout << "\033c";
}







void menu()
{
	cout << "                 |======================================================================|" << endl;
	cout << "                 |-----------------------------1.查询年历-------------------------------|" << endl;
	cout << "                 |-----------------------------2.查询月历-------------------------------|" << endl;
	cout << "                 |--------3.查询某天的数据（距今多少天，星期几，是否公历节日）----------|" << endl;
	cout << "                 |-----------------------------4.增加待办-------------------------------|" << endl;
	cout << "                 |-----------------------------5.删除待办-------------------------------|" << endl;
	cout << "                 |-----------------------------6.修改待办-------------------------------|" << endl;
	cout << "                 |-----------------------------7.查询待办-------------------------------|" << endl;
	cout << "                 |----------------     e.退出    s.保存   c.清屏     -------------------|" << endl;
	cout << "                 |======================================================================|" << endl;
}


int main()
{
	ios::sync_with_stdio(false);
	Link link;
	//链表初始化
	Init(&link);
	//加载信息
	Load(&link);
	//菜单
	menu();
	char input;
	while (1)
	{
		cout << "请选择功能：";
		cin >> input;

		if (input == '1')
		{
			ShowYear(&link);	//打印某一年的年历
		}
		else if (input == '2')
		{
			ShowMonthDate(&link);	//打印某年某月的日历
		}
		else if (input == '3')
		{
			FindSomeday(&link);
		}
		else if (input == '4')
		{
			AddBackLog(&link);
		}
		else if (input == '5')
		{
			DeleBackLog(&link);
		}
		else if (input == '6')
		{
			MondifyBackLog(&link);
		}
		else if (input == '7')
		{
			FindBackLog(&link);
		}
		else if (input == 'e')
		{
			cout << "谢谢！！！" << endl;
			return 1 - 1;
		}
		else if (input == 's')
		{
			Save(&link);
		}
		else if (input == 'c')
		{
			Clean();
			menu();
		}
		else
		{
			cout << "请输入正确的选项！！！！！" << endl;
		}
	}
	return 0;
}