-- Active: 1699491496375@@127.0.0.1@3306@sakila
-- <영화 등급>
-- G : 모든 연령대 시청가능
-- PG (Parental Guidance) : 모든 연령대 시청가능하나, 부모의 지도가 필요
-- PG-13 : 13세 미만의 아동에게 부적절 할 수 있으며, 부모의 주의를 요함
-- R(Restricted) : 17세 또는 그이상의 성인
-- NC-17 : 17세 이하 시청 불가


	-- 1. 고객별 지불 금액의 총합을 구하라
	
	select customer_id, sum(amount)
	from payment
	group by customer_id;
	
	-- 2. 위 쿼리에서 고객ID 대신 고객의 first_name, last_name을 출력하라
	
	select CS.first_name, CS.last_name, sum(amount)
	from payment PM join customer CS on PM.customer_id = CS.customer_id
	group by CS.first_name, CS.last_name;
	3. 고객ID별 총 대여 수를 출력(대여 수 많은 고객부터)
	select customer_id, count(rental_id)
	from rental
	group by customer_id
	order by count(rental_id) desc;
	
	-- 4. 위 쿼리에서 고객ID 대신 고객의 first_name, last_name을 출력하라
	select CS.first_name, CS.last_name, count(rental_id)
	from rental RT join customer CS on RT.customer_id = CS.customer_id
	group by CS.first_name, CS.last_name
	order by count(rental_id) desc;
	
	
	-- 5. action 분야 영화의 다음 속성들을 출력하시오
	-- 필름번호, 제목, 설명, 분야, 발매년도, 언어
	
	select FL.film_id as 필름번호, FL.title as 제목, FL.description as 설명, CG.name as 분야
	, FL.release_year as 발매년도, LG.name as 언어
	from film as FL join film_category as FC on FL.film_id = FC.film_id
	join category as CG on FC.category_id = CG.category_id
	join language as LG on FL.language_id = LG.language_id
	where CG.name = 'action';
	
	-- 6. 출연작이 많은 순으로 배우의 first_name, last_name, 작품수 를 출력하시오
	select A.actor_id, A.first_name, A.last_name, count(film_id) as "작품수"
	from film_actor FA join actor as A
	on FA.actor_id = A.actor_id
	group by A.actor_id, A.first_name, A.last_name
	order by count(film_id) desc;
	
	-- 7. MARY KEITEL의 출연작을 영화제목 오름차순으로 출력하시오. 출력 컬럼은 다음과 같다.
	-- first_name, last_name, 영화제목, 출시일, 대여 비용
	select AC.first_name, AC.last_name, FL.title, FL.release_year, FL.rental_rate
	from actor AC join film_actor FA on AC.actor_id = FA.actor_id
	join film FL on FA.film_id = FL.film_id
	where AC.first_name = 'MARY' and AC.last_name = 'KEITEL'
	order by FL.title;
	
	-- 8. 배우의 'R' 등급 영화 작품 수를 카운트하여, 가장 많은 작품수를 가지는 배우부터 출력하시오, 출력 컬럼은 다음과 같다.
	-- actor_id, first_name, last_name, 'R'등급 작품 수
	select AC.actor_id, AC.first_name, AC.last_name, count(FL.title)
	from film FL join film_actor FA on FL.film_id = FA.film_id
	join actor AC on AC.actor_id = FA.actor_id
	where FL.rating = 'R'
	group by AC.actor_id, AC.first_name, AC.last_name
	order by count(FL.title) desc;
	
	-- 9. 'R' 등급 영화에 출연한 적이 없는 배우의 first_name, last_name, 출연영화제목을 출시일 순으로 출력하시오
	select AC.first_name, AC.last_name, FL.title
	from film FL join film_actor FA on FL.film_id = FA.film_id
	join actor AC on AC.actor_id = FA.actor_id
	where AC.actor_id not in (select FA.actor_id
	        from film FL join film_actor FA on FL.film_id = FA.film_id
	        where rating = 'R')
	order by FL.release_year;
	
	-- 10. 영화 'AGENT TRUMAN' 를 보유하고 있는 매장의 정보를 아래와 같이 출력함.
	-- 영화제목, 매장ID, 매장staff first_name, 매장staff last_name, 매장의 address, address2
	-- , district, city, country, 해당 타이틀 "보유수량"
	
	select FL.title, ST.store_id, SF.first_name, SF.last_name, AD.address, AD.address2
	, AD.district, CT.city, CU.country, count(FL.title) as "보유수량"
	from film FL join inventory IV on FL.film_id = IV.film_id
	join store ST on IV.store_id = ST.store_id
	join staff SF on ST.store_id = SF.store_id
	join address AD on ST.address_id = AD.address_id
	join city CT on AD.city_id = CT.city_id
	join country CU on CT.country_id = CU.country_id
	where FL.title = 'AGENT TRUMAN'
	group by FL.title, ST.store_id, SF.first_name, SF.last_name, AD.address, AD.address2
	, AD.district, CT.city, CU.country;
	
	-- 11. 영화 'AGENT TRUMAN' 를 보유하고 있는 매장의 정보와 해당 타이틀의 대여 정보를(대여 정보가 없을 경우에는 관련 컬럼은 null 처리) 아래와 같이 출력함.
	-- 영화제목, 매장ID, 인벤토리ID, 매장의 address, address2, district, city, country,
	-- 대여 일자, 회수일자, 대여고객의 first_name, last_name
	
	select FL.title, ST.store_id, IV.inventory_id, AD.address, AD.address2
	, AD.district, CT.city, CU.country, RT.rental_date, RT.return_date, CS.first_name, CS.last_name
	from film FL join inventory IV on FL.film_id = IV.film_id
	join store ST on IV.store_id = ST.store_id
	join address AD on ST.address_id = AD.address_id
	join city CT on AD.city_id = CT.city_id
	join country CU on CT.country_id = CU.country_id
	left join rental RT on IV.inventory_id = RT.inventory_id
	join customer CS on RT.customer_id = CS.customer_id
	where FL.title = 'AGENT TRUMAN';
	
	-- 12. 대여된 영화 타이틀과 대여회수를 출력하시오(대여 회수 내림차순)
	select FL.title, sum(rental_info.rental_cnt)
	from inventory IV join (select inventory_id, count(rental_id) as rental_cnt
	        from rental
	        group by inventory_id) as rental_info
	on IV.inventory_id = rental_info.inventory_id
	join film FL on IV.film_id = FL.film_id
	group by FL.title
	order by sum(rental_info.rental_cnt) desc;
	
	-- 13. 고객의 지불정보를 총지불금액 내림차순, 다음과 같이 출력하시오
	-- 고객의  customer_id, first_name, last_name, 총지불금액, 고객의 주소 address, address2, district
	-- , city, country
	
	select CS.customer_id, CS.first_name, CS.last_name, 
	sum(PM.amount), AD.address, AD.district
	, CT.city, CU.country
from payment PM join customer CS 
	on PM.customer_id = CS.customer_id
	join address AD on CS.address_id = AD.address_id
	join city CT on AD.city_id = CT.city_id
	join country CU on CT.country_id = CU.country_id
group by CS.customer_id, CS.first_name, CS.last_name, 
	AD.address, AD.district, CT.city, CU.country
order by sum(PM.amount) desc;
	
	-- 14. 총 지불 금액별 고객 등급을 출력하고자 한다. 등급 구분과 출력 컬럼은 다음과 같다.(case 문 사용)
	-- 'A' : 총 지불금액이 200 이상
	-- 'B' : 총 지불금액이 200 미만 100 이상
	-- 'C' : 총 지불금액이 100 미만 고객
	-- 고객의 customer_id, firs_name, last_name, 총 지불금액, 등급
	-- 총 지불금액이 많은 고객부터 출력
	select CS.customer_id, CS.first_name, CS.last_name, 
	sum(PM.amount), 
        case when (sum(PM.amount) >= 200) then 'A'
	when (sum(PM.amount) >= 100) then 'B'
	else 'C' 
        end as customer_grade
from payment PM join customer CS 
on PM.customer_id = CS.customer_id
group by CS.customer_id, CS.first_name, CS.last_name
order by sum(PM.amount) desc;
	
	-- 15. DVD 대여 후 아직 반납하지 않은 고객정보를 다음의 정보로 출력한다.(case 문 사용)
	-- 영화타이틀, 인벤토리ID, 매장ID, 고객의 first_name, last_name, 대여일자, 고객등급
	select FL.title, IV.inventory_id, IV.store_id, CS.first_name, CS.last_name
	, RT.rental_date, case when (sum(PM.amount) >= 200) then 'A'
	        when (sum(PM.amount) >= 100) then 'B'
	                    else 'C' end as customer_grade
	from rental RT join customer CS on RT.customer_id = CS.customer_id
	join inventory IV on RT.inventory_id = IV.inventory_id
	join film FL on IV.film_id = FL.film_id
	join store ST on IV.store_id = ST.store_id
	join payment PM on CS.customer_id = PM.customer_id
	where RT.return_date is null
	group by FL.title, IV.inventory_id, IV.store_id, CS.first_name, CS.last_name
	, RT.rental_date;
	
	
	-- 16. '2005-08-01' 부터 '2005-08-15' 사이, Canada(country) Alberta(district) 주에서 대여한 영화의 타이틀 정보를 아래와 같이 출력하시오
	-- 대여일, 영화 타이틀, 인벤토이ID, 매장ID, 매장 전체 주소
	
	select RT.rental_date, FL.title, IV.inventory_id, IV.store_id, AD.address, AD.address2, AD.district, CT.city, CU.country
	from rental RT join inventory IV on RT.inventory_id = IV.inventory_id
	join store ST on IV.store_id = ST.store_id
	join address AD on ST.address_id = AD.address_id
	join city CT on AD.city_id = CT.city_id
	join country CU on CT.country_id = CU.country_id
	join film FL on IV.film_id = FL.film_id
	where rental_date between '2005-08-01' and '2005-08-15'
	and AD.district = 'Alberta'
	and CU.country = 'Canada';
	
	-- 17. 도시별 'Horror' 영화 대여회수를 알고자 한다. 도시와 대여수를 출력하라. 대여수 내림차순, 도시명 오름차순으로 정렬하시오
	
	select CT.city, count(FL.title)
	from film FL join film_category FC on FL.film_id = FC.film_id
	join category CG on FC.category_id = CG.category_id
	join inventory IV on FL.film_id = IV.film_id
	join rental RT on IV.inventory_id = RT.inventory_id
	join customer CS on RT.customer_id = CS.customer_id
	join address AD on CS.address_id = AD.address_id
	join city CT on AD.city_id = CT.city_id
	join country CU on CT.country_id = CU.country_id
	where CG.name = 'Horror'
	group by CT.city
	order by count(FL.title) desc, CT.city;
	
	-- 18. 각 store 별 총 대여금액을 출력하시오.
	select ST.store_id, sum(amount)
	from rental RT join payment PM on RT.rental_id = PM.rental_id
	join inventory IV on RT.inventory_id = IV.inventory_id
	join store ST on IV.store_id = ST.store_id
	group by ST.store_id;
	
	-- 19. 대여된 영화 중 대여기간이 연체된 건을 다음의 정보로 조회하시오.(현재날짜기준)
	-- 영화타이틀. inventory_id, 대여일, 반납일, 기준대여기간, 실제대여기간
	-- ** 아직 반납이 되지 않은 경우, 실제대여기간 컬럼에 'Unknown' 출력
	select FL.title, IV.inventory_id, RT.rental_date, RT.return_date, FL.rental_duration, IFNULL(DATEDIFF(RT.return_date, RT.rental_date), 'Unknown')
	from rental RT join inventory IV on RT.inventory_id = IV.inventory_id
	join film FL on IV.film_id = FL.film_id
	where DATEDIFF(IFNULL(RT.return_date, curdate()), RT.rental_date) > FL.rental_duration;
	
	
	-- 20. 고객별 연체 건수가 많은 수부터 출력하시오(고객 first_name, last_name, 연체건수)
	-- 연체기준은 현재날짜
	select CS.first_name, CS.last_name, count(RT.rental_id)
	from rental RT join inventory IV on RT.inventory_id = IV.inventory_id
	join film FL on IV.film_id = FL.film_id
	join customer CS on RT.customer_id = CS.customer_id
	where datediff(IFNULL(RT.return_date, curdate()), RT.rental_date) > FL.rental_duration
	group by CS.first_name, CS.last_name
	order by count(RT.rental_id) desc;
	
	-- 21. 대여횟수 상위 5위 고객이 대여한 영화의 title을 알파벳순으로 출력
	-- 출력 컬럼 : 고객이름(first, last), 영화제목, 총 대여수
	select CS.first_name, CS.last_name, FL.title, top5.tot_cnt
	from (select customer_id, count(rental_id) as tot_cnt
	        from rental
	        group by customer_id
	        order by count(rental_id) desc
	        limit 5) as top5 join rental RT on top5.customer_id = RT.customer_id
	join inventory IV on RT.inventory_id = IV.inventory_id
	join film FL on IV.film_id = FL.film_id
	join customer CS on top5.customer_id = CS.customer_id
	order by top5.tot_cnt desc, FL.title;
	
	
	
	-- 22. 배우 'WALTER TORN' 보다 출연작이 많은 배우의 정보를, 배우ID, 배우 이름(first_name, last_name), 출연작 타이틀, 작품 출시일을 출력하시오(정렬순서: 배우ID, 타이틀, 출시일)
	
	select id, famous_actor.f_name, famous_actor.l_name, FL.title, FL.release_year
	from (select AC.actor_id as id, AC.first_name as f_name, AC.last_name as l_name, count(film_id) as cnt
	        from actor AC join film_actor FA on AC.actor_id = FA.actor_id
	        group by id, f_name, l_name
	        having cnt > (select count(film_id)
	                from actor AC join film_actor FA on AC.actor_id = FA.actor_id
	                where AC.first_name = 'WALTER'
	                and AC.last_name = 'TORN')) as famous_actor
	join film_actor FA on famous_actor.id = FA.actor_id
	join film FL on FA.film_id = FL.film_id
	order by id, FL.title, FL.release_year;
	
