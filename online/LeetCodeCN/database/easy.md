# Easy

## [1350](https://leetcode-cn.com/problems/students-with-invalid-departments/) 院系无效的学生

``` sql
SELECT `id`, `name` FROM `students`
WHERE `department_id` NOT IN (
    SELECT `id` FROM `departments`
);
```

``` sql
--  Slower
SELECT `id`, `name` from `students`
WHERE NOT EXISTS (
    SELECT * FROM `departments` WHERE `students`.`department_id` = `departments`.`id`
);
```

## [1378](https://leetcode-cn.com/problems/replace-employee-id-with-the-unique-identifier/) 使用唯一标识码替换员工ID

``` sql
SELECT `unique_id`, `name`
FROM `Employees`
LEFT JOIN `EmployeeUNI` ON `Employees`.`id` = `EmployeeUNI`.`id`;
```

## [1068](https://leetcode-cn.com/problems/product-sales-analysis-i/) 产品销售分析

``` sql
SELECT `product_name`, `year`, `price`
FROM `Sales` INNER JOIN `Product`
USING (`product_id`); -- ON `Sales`.`product_id` = `Product`.`product_id`
```

## [1527](https://leetcode-cn.com/problems/patients-with-a-condition/) Patients With a Condition

``` sql
SELECT * FROM `Patients`
WHERE `conditions` LIKE "%DIAB1%";
```

## [1303](https://leetcode-cn.com/problems/find-the-team-size/) 求团队人数

``` sql
-- 窗口函数（推荐）
SELECT
    employee_id,
    COUNT(employee_id) OVER(PARTITION BY team_id) AS `team_size`
FROM `Employee`;
```

``` sql
-- 中间表
SELECT `employee_id`, `team_size`
FROM `Employee`
LEFT JOIN (
    SELECT `team_id`, COUNT(`team_id`) AS `team_size`
    FROM `Employee`
    GROUP BY `team_id`
) AS `Team` -- Every derived table must have its own alias
USING (`team_id`);
```

``` sql
-- 自连接 Self Join
SELECT `e1`.`employee_id`, COUNT(*) AS `team_size`
FROM `Employee` AS `e1`
INNER JOIN `Employee` AS `e2` USING (`team_id`)
GROUP BY `employee_id`
ORDER BY `employee_id`;
```

``` sql
-- 相关子查询
SELECT `e1`.`employee_id`, (
    SELECT COUNT(*) FROM `Employee` AS `e2`
    WHERE `e1`.`team_id` = `e2`.`team_id`
) AS `team_size`
FROM `Employee` AS `e1`;
```

## [613](https://leetcode-cn.com/problems/shortest-distance-in-a-line/) 直线上最短的距离

``` sql
SELECT MIN(ABS(`x1`.`x` - `x2`.`x`)) AS `shortest`
FROM `point` AS `x1`, `point` AS `x2`
WHERE `x1`.`x` != `x2`.`x`;
```

## [1609](https://leetcode-cn.com/problems/product-sales-analysis-ii/) 产品销售分析

``` sql
SELECT `product_id`, SUM(`quantity`) AS `total_quantity`
FROM `Sales`
GROUP BY `product_id`;
```

## [595](https://leetcode-cn.com/problems/big-countries/) 大的国家

``` sql
SELECT `name`, `population`, `area`
FROM `World`
WHERE `population` > 25000000 OR `area` > 3000000;
```

## [627](https://leetcode-cn.com/problems/swap-salary/) 交换工资

``` sql
-- CASE WHEN ... THEN ... ELSE ... END
UPDATE `salary` SET `sex` = CASE
    WHEN `sex` = 'm' THEN 'f'
    ELSE 'm'
END;
```

## [1251](https://leetcode-cn.com/problems/average-selling-price/) 平均售价

- `ROUND(value, precision)` `ROUND(3.14159, 2)` 四舍五入到两位小数
- `BETWEEN v1 AND v2` 值落在[v1, v2]闭区间上

``` sql
-- 相关子查询
SELECT
    `product_id`,
    ROUND(
        SUM((SELECT `price` * `units`
        FROM `Prices`
        WHERE
            `Prices`.`product_id` = `UnitsSold`.`product_id`
            AND `start_date` <= `purchase_date`
            AND `end_date` >= `purchase_date` -- `purchase_date` BETWEEN `start_date` AND `end_date`
        )) / SUM(`units`)
    , 2) AS `average_price`
FROM `UnitsSold`
GROUP BY `product_id`;
```

``` sql
-- （推荐）JOIN 临时表
-- Slower
SELECT
    `product_id`,
    ROUND(SUM(`sales`) / SUM(`units`), 2) AS `average_price`
FROM (
    SELECT
        `product_id`,
        `price` * `units` AS `sales`,
        `units`
    FROM `UnitsSold`
    INNER JOIN `Prices` USING (`product_id`)
    WHERE `purchase_date` BETWEEN `start_date` AND `end_date`
) AS `Summary`
GROUP BY `product_id`;
```

## [584](https://leetcode-cn.com/problems/find-customer-referee/) 寻找用户推荐人

- 当列可能为 `NULL`，务必考虑 `NULL` 的情况，使用 `IFNULL()`， `IS NULL` 等进行判定。

``` sql
SELECT `name` FROM `customer`
WHERE `referee_id` IS NULL OR `referee_id` != 2;
```

## [1517](https://leetcode-cn.com/problems/find-users-with-valid-e-mails/) 寻找拥有有效邮箱的用户

- MySQL [正则表达式](https://dev.mysql.com/doc/refman/8.0/en/regexp.html#operator_regexp)
- [MySQL Regular Expression on GeeksforGeeks](https://www.geeksforgeeks.org/mysql-regular-expressions-regexp/)

``` sql
SELECT * FROM `Users`
WHERE `mail` REGEXP "^[a-zA-Z]+[a-zA-Z0-9_./\-]*@leetcode.com$"
```

## [620](https://leetcode-cn.com/problems/not-boring-movies/) 有趣的电影

- `LIKE` 默认是大小写不敏感的，如果需要大小写敏感，则可以使用 `LIKE BINARY`。
- MySQL 5.6 与 8.0 使用了不同的单词边界，见 [StackOverflow 上的这个解答](https://stackoverflow.com/a/60906360/8762529)。

``` sql
SELECT * FROM `cinema`
WHERE `id` % 2 = 1 AND `description` NOT LIKE "%boring%"
ORDER BY `rating` DESC;
```

``` sql
-- 使用单词边界更严谨
SELECT * FROM `cinema`
WHERE `id` % 2 = 1 AND `description` NOT REGEXP "\\bboring\\b"
ORDER BY `rating` DESC;
```

## [196](https://leetcode-cn.com/problems/delete-duplicate-emails/) 删除重复的电子邮箱

注意到，这里如果只是使用一层 SELECT，MySQL 会报错。报错原因可参考 [StackOverflow](https://stackoverflow.com/a/9843719/8762529)。

``` sql
DELETE FROM `Person` WHERE `Id` NOT IN (
    SELECT `MinId` FROM (
        SELECT MIN(`Id`) AS `MinId` FROM `Person` GROUP BY `Email`
    ) AS `t`
)
```

## [175](https://leetcode-cn.com/problems/combine-two-tables/) 组合两个表

``` sql
SELECT `FirstName`, `LastName`, `City`, `State` FROM `Person`
LEFT OUTER JOIN `Address` USING (`PersonId`)
```

## [176](https://leetcode-cn.com/problems/second-highest-salary/) 第二高的工资

**注意对 `NULL` 的处理**

``` sql
SELECT (
    SELECT DISTINCT `Salary` FROM `Employee`
    ORDER BY `Salary` DESC
    LIMIT 1
    OFFSET 1
) AS `SecondHighestSalary`;
```

## [177](https://leetcode-cn.com/problems/nth-highest-salary/) 第 N 高的工资

注意对 [SQL 变量](https://dev.mysql.com/doc/refman/8.0/en/stored-program-variables.html)的处理。

``` sql
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE offset_val INT DEFAULT N-1;
  RETURN (
      SELECT DISTINCT `Salary` FROM `Employee`
      ORDER BY `Salary` DESC
      LIMIT 1 OFFSET offset_val
  );
END
```

## [1581](https://leetcode-cn.com/problems/customer-who-visited-but-did-not-make-any-transactions/) Customer Who Visited but Did Not Make Any Transactions

``` sql
SELECT `customer_id`, COUNT(*) AS `count_no_trans` FROM `Visits`
WHERE `visit_id` NOT IN (
    SELECT `visit_id` FROM `Transactions`
)
GROUP BY `customer_id`
ORDER BY `count_no_trans` DESC
```

## [1587](https://leetcode-cn.com/problems/bank-account-summary-ii) Bank Account Summary II

``` sql
SELECT `name`, SUM(`amount`) AS `balance` FROM `Users`
LEFT OUTER JOIN `Transactions` USING (`account`)
GROUP BY `account`
HAVING `balance` > 10000
```

## [1565](https://leetcode-cn.com/problems/unique-orders-and-customers-per-month/) Unique Orders and Customers Per Month

注意 MySQL 的[日期格式化函数](https://dev.mysql.com/doc/refman/8.0/en/date-and-time-functions.html#function_date-format)。

``` sql
SELECT
    DATE_FORMAT(`order_date`, '%Y-%m') AS `month`,
    COUNT(*) AS `order_count`,
    COUNT(DISTINCT `customer_id`) AS `customer_count`
FROM `Orders`
WHERE `invoice` > 20
GROUP BY `month`
```

## [1571](https://leetcode-cn.com/problems/warehouse-manager/) 仓库经理

``` sql
SELECT `name` AS `warehouse_name`, SUM(`Width` * `Length` * `Height` * `units`) AS `volume`
FROM `Warehouse`
INNER JOIN `Products` USING (`product_id`)
GROUP BY `warehouse_name`
```

## [1148](https://leetcode-cn.com/problems/article-views-i/) 文章浏览

``` sql
SELECT
DISTINCT `author_id` AS `id`
FROM `Views`
WHERE `author_id` = `viewer_id`
ORDER BY `id` ASC
```

## [1082](https://leetcode-cn.com/problems/sales-analysis-i/) 销售分析 I

``` sql
SELECT `actor_id`, `director_id` FROM `ActorDirector`
GROUP BY `actor_id`, `director_id`
HAVING COUNT(*) >= 3
```

## [586](https://leetcode-cn.com/problems/customer-placing-the-largest-number-of-orders/) 订单最多的客户

``` sql
SELECT `customer_number`
FROM `orders`
GROUP BY `customer_number`
ORDER BY COUNT(*) DESC
LIMIT 1
```

``` sql
-- 如果多位客户订单数并列最多
SELECT `customer_number`
FROM `orders`
GROUP BY `customer_number`
HAVING COUNT(*) = (
    SELECT COUNT(*) AS `count`
    FROM `orders`
    GROUP BY `customer_number`
    ORDER BY `count` DESC
    LIMIT 1
)
```

## [1082](https://leetcode-cn.com/problems/sales-analysis-i/) 销售分析 I

``` sql
SELECT `seller_id`
FROM `Sales`
GROUP BY `seller_id`
HAVING SUM(`price`) = (
    SELECT SUM(`price`) AS `sum` FROM `Sales`
    GROUP BY `seller_id`
    ORDER BY `sum` DESC
    LIMIT 1
)
```

## [511](https://leetcode-cn.com/problems/game-play-analysis-i/) 游戏玩法分析

``` sql
SELECT `player_id`, MIN(`event_date`) AS `first_login`
FROM `Activity`
GROUP BY `player_id`
```

## [577](https://leetcode-cn.com/problems/employee-bonus/) 员工奖金

``` sql
SELECT `name`, `bonus` FROM `Employee`
LEFT OUTER JOIN `Bonus` USING (`empId`)
WHERE `bonus` IS NULL OR `bonus` < 1000
```

## [181](https://leetcode-cn.com/problems/employees-earning-more-than-their-managers/) 超过经理收入的员工

``` sql
-- 表连接
-- faster
SELECT `Employee`.`Name` AS `Employee` FROM `Employee`
LEFT OUTER JOIN `Employee` AS `Manager` ON `Employee`.`ManagerId` = `Manager`.`Id`
WHERE `Employee`.`Salary` > `Manager`.`Salary`
```

``` sql
-- 相关子查询
-- slower
SELECT `E`.`Name` AS `Employee`
FROM `Employee` AS `E`
WHERE `E`.`Salary` > (
    SELECT `I`.`Salary`
    FROM `Employee` AS `I`
    WHERE `I`.`Id` = `E`.`ManagerId`
)
```

## [1327](https://leetcode-cn.com/problems/list-the-products-ordered-in-a-period/) 列出指定时间段内所有的下单产品

``` sql
SELECT `product_name`, SUM(`unit`) AS `unit` FROM `Products`
INNER JOIN `Orders` USING (`product_id`)
WHERE EXTRACT(YEAR_MONTH FROM `order_date`) = 202002
GROUP BY `product_name`
HAVING SUM(`unit`) >= 100
```

## [630](https://leetcode-cn.com/problems/consecutive-available-seats/) 连续空余座位

``` sql
SELECT `a`.`seat_id` FROM `cinema` AS `a`
WHERE `a`.`free` = 1 AND EXISTS (
    SELECT true FROM `cinema` AS `b`
    WHERE (`b`.`seat_id` = `a`.`seat_id` - 1 AND `b`.`free` = 1)
    OR (`b`.`seat_id` = `a`.`seat_id` + 1 AND `b`.`free` = 1)
)
ORDER BY `a`.`seat_id` ASC
```

## [607](https://leetcode-cn.com/problems/sales-person/) 销售员

``` sql
SELECT `salesperson`.`name` FROM `salesperson`
WHERE `salesperson`.`name` NOT IN (
    SELECT `salesperson`.`name` FROM `salesperson`
    INNER JOIN `orders` USING (`sales_id`)
    INNER JOIN `company` USING (`com_id`)
    WHERE `company`.`name` = 'RED'
)
```

## [1485](https://leetcode-cn.com/problems/group-sold-products-by-the-date/) 按日期分组销售产品

注意 `COUNT(DISTINCT)` 以及 [`GROUP_CONCAT`](https://dev.mysql.com/doc/refman/8.0/en/aggregate-functions.html#function_count) 函数的使用。

``` sql
SELECT
    `sell_date`,
    COUNT(DISTINCT `product`) AS `num_sold`,
    GROUP_CONCAT(DISTINCT `product` ORDER BY `product` ASC SEPARATOR ',') AS `products`
FROM `Activities`
GROUP BY `sell_date`
ORDER BY `sell_date` ASC
```

## [1294](https://leetcode-cn.com/problems/weather-type-in-each-country/) 不同国家的天气类型

注意 `CASE WHEN ... THEN ... WHEN ... THEN ... ELSE ... END` 的使用，参见 [MySQL Control Flow](https://dev.mysql.com/doc/refman/8.0/en/flow-control-functions.html)。

``` sql
SELECT
    `country_name`,
    CASE WHEN AVG(`weather_state`) <= 15 THEN 'Cold'
    WHEN AVG(`weather_state`) >= 25 THEN 'Hot'
    ELSE 'Warm'
    END AS `weather_type`
FROM `Countries`
INNER JOIN `Weather` USING (`country_id`)
WHERE EXTRACT(YEAR_MONTH FROM `day`) = 201911
GROUP BY `country_name`
```

## [1075](https://leetcode-cn.com/problems/project-employees-i/) 项目员工 I

``` sql
SELECT `project_id`, ROUND(SUM(`experience_years`) / COUNT(`employee_id`), 2) AS `average_years`
FROM `Project`
INNER JOIN `Employee` USING (`employee_id`)
GROUP BY `project_id`
```

## [1407](https://leetcode-cn.com/problems/top-travellers/) 排名靠前的旅行者

``` sql
SELECT `name`, IFNULL(SUM(`distance`), 0) AS `travelled_distance`
FROM `Users`
LEFT OUTER JOIN `Rides` ON `Users`.`id` = `Rides`.`user_id`
GROUP BY `name`
ORDER BY `travelled_distance` DESC, `name` ASC
```

## [610](https://leetcode-cn.com/problems/triangle-judgement/) 判断三角形

``` sql
SELECT `x`, `y`, `z`, CASE
    WHEN `x` + `y` > `z` AND `y` + `z` > `x` AND `x` + `z` > `y` THEN 'Yes'
    ELSE 'No'
END AS `triangle`
FROM `triangle`
```

## [1511](https://leetcode-cn.com/problems/customer-order-frequency/) 消费者下单频率

在 MySQL 里，连表查询比相关子查询更快。

``` sql
-- 重复的临时表方案
-- slower 冗余（不推荐）
SELECT `a`.`customer_id`, `a`.`name` FROM `Customers` AS `a`
WHERE EXISTS (
    SELECT true FROM (
    SELECT
        `customer_id`,
        `name`,
        EXTRACT(YEAR_MONTH FROM `order_date`) AS `yyyymm`,
        SUM(`price` * `quantity`) AS `total` FROM `Customers`
    INNER JOIN `Orders` USING (`customer_id`)
    INNER JOIN `Product` USING (`product_id`)
    GROUP BY `customer_id`, `yyyymm`
) AS `b` WHERE `a`.`customer_id` = `b`.`customer_id` AND `yyyymm` = 202006 AND `total` >= 100
) AND EXISTS (
    SELECT true FROM (
    SELECT
        `customer_id`,
        `name`,
        EXTRACT(YEAR_MONTH FROM `order_date`) AS `yyyymm`,
        SUM(`price` * `quantity`) AS `total` FROM `Customers`
    INNER JOIN `Orders` USING (`customer_id`)
    INNER JOIN `Product` USING (`product_id`)
    GROUP BY `customer_id`, `yyyymm`
) AS `b` WHERE `a`.`customer_id` = `b`.`customer_id` AND `yyyymm` = 202007 AND `total` >= 100
)
```

``` sql
--- 连表查询
SELECT `customer_id`, `name` FROM (
    SELECT
        `customer_id`,
        `name`,
        EXTRACT(YEAR_MONTH FROM `order_date`) AS `yyyymm`,
        SUM(`price` * `quantity`) AS `total` FROM `Customers`
    INNER JOIN `Orders` USING (`customer_id`)
    INNER JOIN `Product` USING (`product_id`)
    WHERE EXTRACT(YEAR_MONTH FROM `order_date`) IN (202006, 202007)
    GROUP BY `customer_id`, `yyyymm`
    HAVING `total` >= 100
) AS `t`
GROUP BY `customer_id`, `name`
HAVING COUNT(*) = 2
```

注意结合 `IF` 可以写出比较好的句子。

``` sql
-- 直接构造 Having 子句
SELECT `customer_id`, `name` FROM (
    SELECT
        `customer_id`,
        `name`,
        EXTRACT(YEAR_MONTH FROM `order_date`) AS `yyyymm`
    FROM `Customers`
    INNER JOIN `Orders` USING (`customer_id`)
    INNER JOIN `Product` USING (`product_id`)
    WHERE EXTRACT(YEAR_MONTH FROM `order_date`) IN (202006, 202007)
    GROUP BY `customer_id`, `name`
    HAVING SUM(IF(`yyyymm` = 202006, `quantity` * `price`, 0)) >= 100
    AND SUM(IF(`yyyymm` = 202007, `quantity` * `price`, 0)) >= 100
) AS `t`
```

## [1607](https://leetcode-cn.com/problems/sellers-with-no-sales/) Sellers With No Sales

``` sql
SELECT `seller_name` FROM `Seller`
WHERE `seller_id` NOT IN (
    SELECT `seller_id` FROM `Seller`
    LEFT OUTER JOIN `Orders` USING (`seller_id`)
    WHERE EXTRACT(YEAR FROM `sale_date`) = 2020
)
ORDER BY `seller_name` ASC
```

## [1211](https://leetcode-cn.com/problems/queries-quality-and-percentage/) 查询结果的质量和占比

``` sql
SELECT
    `query_name`,
    ROUND(AVG(`rating` / `position`), 2) AS `quality`,
    ROUND((SUM(IF(`rating` < 3, 1, 0)) / COUNT(*)) * 100, 2) AS `poor_query_percentage`
FROM `Queries`
GROUP BY `query_name`
```

## [1435](https://leetcode-cn.com/problems/create-a-session-bar-chart/) 制作会话柱状图

注意学习使用 `UNION` 建立新表的技术。

``` sql
SELECT `bin`, IFNULL(`total`, 0) AS `total` FROM (
    SELECT CASE
        WHEN `duration` < 5 THEN '[0-5>'
        WHEN `duration` < 10 THEN '[5-10>'
        WHEN `duration` < 15 THEN '[10-15>'
        ELSE '15 or more'
    END AS `bin`, COUNT(*) AS `total`
    FROM (
        SELECT `duration` / 60 AS `duration` FROM `Sessions`
    ) AS `t1`
    GROUP BY `bin`
) AS `t2`
RIGHT JOIN (
    SELECT '[0-5>' AS `bin` UNION SELECT '[5-10>' UNION SELECT '[10-15>' UNION SELECT '15 or more'
) AS `t3`
USING (`bin`)
```

## [1623](https://leetcode-cn.com/problems/all-valid-triplets-that-can-represent-a-country/) 三人代表国家队

``` sql
SELECT
    `SchoolA`.`student_name` AS `member_A`,
    `SchoolB`.`student_name` AS `member_B`,
    `SchoolC`.`student_name` AS `member_C`
FROM `SchoolA`, `SchoolB`, `SchoolC`
WHERE `SchoolA`.`student_name` != `SchoolB`.`student_name`
AND `SchoolA`.`student_name` != `SchoolC`.`student_name`
AND `SchoolB`.`student_name` != `SchoolC`.`student_name`
AND `SchoolA`.`student_id` != `SchoolB`.`student_id`
AND `SchoolA`.`student_id` != `SchoolC`.`student_id`
AND `SchoolB`.`student_id` != `SchoolC`.`student_id`
```

## [1633](https://leetcode-cn.com/problems/percentage-of-users-attended-a-contest/) 各赛事的用户注册率

注意一下两种写法是等价的：

``` sql
SELECT `contest_id`, ROUND(COUNT(`user_id`) / (SELECT COUNT(*) FROM `Users`) * 100, 2)  AS `percentage`
FROM `Register`
GROUP BY `Register`.`contest_id`
ORDER BY `percentage` DESC, `contest_id` ASC
```

``` sql
WITH `t1` AS (
    SELECT COUNT(`user_id`) AS `user_count` FROM `Users`
)
SELECT `contest_id`, ROUND(COUNT(`user_id`) / `t1`.`user_count` * 100, 2)  AS `percentage`
FROM `Register`, `t1`
GROUP BY `Register`.`contest_id`
ORDER BY `percentage` DESC, `contest_id` ASC
```

因为 MySQL 可以自行优化非关联子查询。

## [1241](https://leetcode-cn.com/problems/number-of-comments-per-post/) 每个帖子的评论数

``` sql
-- Slower
WITH `t1` AS (
    SELECT DISTINCT `sub_id` AS `post_id`
    FROM `Submissions`
    WHERE `parent_id` IS NULL
), `t2` AS (
    SELECT DISTINCT `post_id`, `sub_id` FROM `t1`
    INNER JOIN `Submissions`
    ON `t1`.`post_id` = `Submissions`.`parent_id`
)
SELECT `t1`.`post_id`, COUNT(`sub_id`) AS `number_of_comments`
FROM `t1`
LEFT OUTER JOIN `t2` ON `t1`.`post_id` = `t2`.`post_id`
GROUP BY `t1`.`post_id`
ORDER BY `post_id` ASC
```

``` sql
-- better
SELECT post_id, COUNT(sub_id) AS number_of_comments FROM (
    SELECT DISTINCT Post.sub_id AS post_id, Submissions.sub_id
    FROM Submissions AS Post
    LEFT OUTER JOIN Submissions ON Post.sub_id = Submissions.parent_id
    WHERE Post.parent_id IS NULL
) AS t1
GROUP BY post_id
ORDER BY post_id ASC
```
